//Submitting this code should not be good if I weren't the author...
//C99 or C++98.
//https://github.com/DRMacIver/Feedback-Arc-Set/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>

//fas_tournament.h
typedef struct {
  size_t size;
  double entries[];
} tournament;

void enable_fas_tournament_debug(int x);

tournament *new_tournament(size_t n);
void del_tournament(tournament *t);
double tournament_get(tournament *t, size_t i, size_t j);
void tournament_set(tournament *t, size_t i, size_t j, double x);

tournament *read_tournament(FILE *f);
tournament *normalize_tournament(tournament *t);

double best_score_lower_bound(tournament *t, size_t n, size_t *items);
double score_fas_tournament(tournament *t, size_t count, size_t *data);
size_t *optimal_ordering(tournament *t, size_t *results);

size_t tie_starting_from(tournament *t, size_t n, size_t *items, size_t start_index);
size_t condorcet_boundary_from(tournament *t, size_t n, size_t *items, size_t start_index);

//optimisation_table.h
typedef struct{
  uint64_t hash;
  size_t length;
  size_t *data;
  double value;
} ot_entry;

typedef struct {
  size_t length;
  size_t occupancy;
  ot_entry *entries;
} optimisation_table;


optimisation_table *optimisation_table_new();
void optimisation_table_del(optimisation_table *ot);
ot_entry *optimisation_table_lookup(optimisation_table *ot, size_t length, size_t *data);

//permutations.h
size_t next_permutation(size_t length, size_t *data);
void shuffle(size_t length, size_t *data);
void reverse(size_t *s, size_t *e);
size_t random_number(size_t n);
void generate_shuffled_range(size_t length, size_t *data);

//population.h
typedef struct {
  double score;
  size_t *data;
} population_member;

typedef struct {
  size_t members_size;
  size_t population_count;
  population_member members[1];
} population;

population *population_new(size_t population_count, size_t members_size);
void population_del(population *p);

void population_heapify(population *p);
int population_contains(population *p, double key, size_t *data);

population_member fittest_member(population *p);
void population_push(population *p, double key, size_t *data);

//fas_tournament.c
#define ACCURACY 0.001
#define SMOOTHING 0.05
#define MAX_MISSES 5
#define MIN_IMPROVEMENT 0.00001

#define FASDEBUG(...) if(_enable_fas_tournament_debug) fprintf(stderr, __VA_ARGS__);

int _enable_fas_tournament_debug = 0;

void enable_fas_tournament_debug(int x){
  _enable_fas_tournament_debug = x;
}

tournament *new_tournament(size_t n){
  size_t size = sizeof(tournament) + sizeof(double) * n * n;
  tournament *t = (tournament *)malloc(size);
  memset(t, '\0', size);
  t->size = n;
  return t;
}

tournament *normalize_tournament(tournament *t){
    double max_total = 0.0;
    for(size_t i = 0; i < t->size; i++){
        for(size_t j = i + 1; j < t->size; j++){
            double total = tournament_get(t, i, j) + tournament_get(t, j, i);
            if(total > max_total) {
                max_total = total;
            }
        }
    }
    tournament *nt = new_tournament(t->size);
    if(max_total <= 0.0){
        for(size_t i = 0; i < t->size; i++){
            for(size_t j = 0; j < t->size; j++){
                tournament_set(nt, i, j, 0.5);
            }
        }
    } else {
        for(size_t i = 0; i < t->size; i++){
            tournament_set(nt, i, i, 0.5);
            for(size_t j = i + 1; j < t->size; j++){
                double tij = tournament_get(t, i, j);
                double tji = tournament_get(t, j, i);
                double bonus = (max_total - (tij + tji)) / 2;
                tij += bonus;
                tji += bonus;
                tij /= max_total;
                tji /= max_total;
                tournament_set(nt, i, j, tij);
                tournament_set(nt, j, i, tji);
            }
        }
    }

    return nt;
}

void del_tournament(tournament *t){
  free(t);
}

typedef struct {
  size_t *buffer;
  optimisation_table *opt_table;
  tournament *_tournament;
} fas_optimiser;

fas_optimiser *new_optimiser(tournament *t){
  fas_optimiser *it = (fas_optimiser *)malloc(sizeof(fas_optimiser));
  it->buffer = (size_t *)malloc(sizeof(size_t) * t->size);
  it->opt_table = optimisation_table_new();
  it->_tournament = t;
  return it;
}

void del_optimiser(fas_optimiser *o){
  free(o->buffer);
  optimisation_table_del(o->opt_table);
  free(o);
}

void reset_optimiser(fas_optimiser *opt){
  optimisation_table_del(opt->opt_table);
  opt->opt_table = optimisation_table_new();
}

size_t tournament_size(tournament *t){
  return t->size;
}

inline double tournament_get(tournament *t, size_t i, size_t j){
  size_t n = t->size;
  assert(i < n); 
  assert(j < n);
  return t->entries[n * i + j];
}

inline void tournament_set(tournament *t, size_t i, size_t j, double x){
  size_t n = t->size;
  assert(i < n); 
  assert(j < n);
  t->entries[n * i + j] = x;
}

double score_fas_tournament(tournament *t, size_t count, size_t *data){
	double score = 0.0;

	for(size_t i = 0; i < count; i++){
		for(size_t j = i + 1; j < count; j++){
			score +=  t->entries[data[i] * t->size + data[j]];
		}
	}

	return score;
}


static size_t count_tokens(char *c){
  if(*c == '\0') return 0;

  size_t count = 0;
  int in_token = !isspace(*c);
  
  while(*c){
    if(isspace(*c)){
      if(in_token) count++;
      in_token = 0;
    } else {
      in_token = 1;
    }
    c++;
  }

  if(in_token) count++;

  return count;
}

static int read_line(size_t *buffer_size, char **buffer, FILE *f){
  if(!*buffer) *buffer = (char *)malloc(*buffer_size);

  size_t written = 0;
  
  for(;;){
    char c = getc(f);

    if(c == EOF){
      if(written) break;
      else return 0;
    }
    if(c == '\n') break;

    if(written == *buffer_size){
      *buffer_size *= 2;
      *buffer = (char *)realloc(*buffer, *buffer_size);
    }

    (*buffer)[written++] = c;
  }

  if(written == *buffer_size){
    *buffer_size *= 2;
    *buffer = (char *)realloc(*buffer, *buffer_size);
  }

  (*buffer)[written] = '\0';

  return 1;
}

static void fail(char *msg){
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

tournament *read_tournament(FILE *f){
  size_t length = 1024;
  char *line = NULL;
  tournament *t;

  if(!read_line(&length, &line, f)){
    fail("No data for read_tournament");
  }

  size_t n = count_tokens(line);

  if(n != 2) fail("Wrong number of entries in header row)"); //

  char *rest = line;

  n = strtoul(line, &rest, 0);

  if(line == rest){
    fail("I didn't understand the starting line");
  } else if (n <= 0){
    fail("Empty tournament");
  }

  t = new_tournament(n);

  while(read_line(&length, &line, f)){
    char *check = line;
    size_t i = strtoul(line, &rest, 0);
    if(rest == check) fail("failed to parse line"); 
    check = rest;
    size_t j = strtoul(rest, &rest, 0);
    if(rest == check) fail("failed to parse line"); 
    check = rest;
    double f = strtod(rest, &rest);
    if(rest == check) fail("failed to parse line"); 

    if(i >= n || j >= n) fail("index out of bounds");

    t->entries[n * i + j] += f;
  }
  free(line);
  fclose(f);
  return t;
}

static int tournament_compare(tournament *t, size_t i, size_t j){
	double x = tournament_get(t, i, j);
	double y = tournament_get(t, j, i);

  if(x < y + ACCURACY && x > y - ACCURACY) return 0;

	if(x >= y) return -1;
	if(y >= x) return +1;
	return 0;
}

static inline void swap(size_t *x, size_t *y){
	if(x == y) return;
	size_t z = *x;
	*x = *y;
	*y = z;
}

int table_optimise(fas_optimiser *o, size_t n, size_t *items){
  tournament *t = o->_tournament;
	if(n <= 1) return 0;
	if(n == 2){
		int c = tournament_compare(t, items[0], items[1]);
		if(c > 0) swap(items, items+1);
		return c > 0;
	}

  ot_entry *ote = optimisation_table_lookup(o->opt_table, n, items);

  double existing_score = score_fas_tournament(t, n, items);

  if(ote->value >= 0){
    // We already have a best calculation for this entry
    if(existing_score < ote->value){
      // We know a better way to order these
      memcpy(items, ote->data, n * sizeof(size_t));
      return 1;
    } else {
      return 0;
    }
  } else {
    size_t *best_value_seen = (size_t *)malloc(n * sizeof(size_t));
    size_t *pristine_copy = (size_t *)malloc(n * sizeof(size_t));
    memcpy(pristine_copy, items, n * sizeof(size_t));
    memcpy(best_value_seen, items, n * sizeof(size_t));

    int changed = 0;

    double best_score_so_far = existing_score;

    for(size_t i = 0; i < n; i++){
      memcpy(items, pristine_copy, n * sizeof(size_t));
      swap(items, items + i);
      table_optimise(o, n-1, items+1);
      double new_score = score_fas_tournament(t, n, items);
      if(new_score > best_score_so_far){
        memcpy(best_value_seen, items, n * sizeof(size_t));
        changed = 1;
        best_score_so_far = new_score;
      }
    }

    ote = optimisation_table_lookup(o->opt_table, n, items);
    memcpy(items, best_value_seen, n * sizeof(size_t));
    ote->value = best_score_so_far;
    memcpy(ote->data, items, n * sizeof(size_t));

    free(best_value_seen);
    free(pristine_copy);
    return changed;
  }
}

int window_optimise(fas_optimiser *o, size_t n, size_t *items, size_t window){
  if(n <= window){
    return table_optimise(o, n, items);
  }
  double last_score = score_fas_tournament(o->_tournament, n, items);
  int changed_at_all = 0;
  int changed = 1;
  while(changed){
    changed = 0;
    for(size_t i = 0; i < n - window; i++){
      changed |= table_optimise(o, window, items + i); 
    }
    double new_score = score_fas_tournament(o->_tournament, n, items);

    double improvement = (new_score - last_score) / last_score;
    
    changed_at_all |= changed; 
    if(improvement < MIN_IMPROVEMENT) break;
    last_score = new_score;
  }

  return changed_at_all;
}


typedef struct {
  size_t index;
  double score;
} index_with_score;

int compare_index_with_score(const void *xx, const void *yy){
  index_with_score *x = (index_with_score*)xx;
  index_with_score *y = (index_with_score*)yy;

  if(x->score < y->score) return -1;
  if(x->score > y->score) return 1;
  return 0;
}

// Insertion sort for now. Everything else is O(n^2) anyway
static void move_pointer_right(size_t *x, size_t offset){
  while(offset){
    size_t *next = x + 1;
    swap(x, next);
    x = next;
    offset--;
  }
}

static void move_pointer_left(size_t *x, size_t offset){
  while(offset){
    size_t *next = x - 1;
    swap(x, next);
    x = next;
    offset--;
  }
}

int single_move_optimise(fas_optimiser *o, size_t n, size_t *items){
  tournament *t = o->_tournament;
  int changed = 1;
  int changed_at_all = 0;
  while(changed){
    changed = 0;
    for(size_t index_of_interest = 0; index_of_interest < n; index_of_interest++){
      double score_delta = 0;

      if(index_of_interest > 0){
        size_t j = index_of_interest;
        do {
          j--;
          score_delta += tournament_get(t, items[index_of_interest], items[j]);
          score_delta -= tournament_get(t, items[j], items[index_of_interest]);

          if(score_delta > 0){
            move_pointer_left(items+index_of_interest, index_of_interest - j);
            changed = 1; 
            break;
          }
        } while(j > 0);
      }

      for(size_t j = index_of_interest + 1; j < n; j++){
        score_delta += tournament_get(t, items[j], items[index_of_interest]);
        score_delta -= tournament_get(t, items[index_of_interest], items[j]);

        if(score_delta > 0){
          move_pointer_right(items+index_of_interest, j - index_of_interest);
          changed = 1; 
          changed_at_all = 1;
          break;
        }
      }
    }
  }
  return changed_at_all;
}

size_t *integer_range(size_t n){
  size_t *results = (size_t *)malloc(sizeof(size_t) * n);
	for(size_t i = 0; i < n; i++){
		results[i] = i;
	}
  return results;
}

int force_connectivity(fas_optimiser *o, size_t n, size_t *items){
  if(!n) return 0;
  int changed = 0;
  tournament *t = o->_tournament;
  for(size_t i = 0; i < n - 1; i++){
    size_t j = i + 1;
    while(j < n && !tournament_compare(t, items[i], items[j])) j++;
    if(j < n){
      changed = 1;
      move_pointer_left(items + j, (j - i - 1));
    }
  }
  return changed;
}


int local_sort(fas_optimiser *o, size_t n, size_t *items){
  tournament *t = o->_tournament;
  int changed = 0;
  for(size_t i = 1; i < n; i++){
    size_t j = i;

    while(j > 0 && tournament_compare(t, items[j], items[j - 1]) <= 0){
      changed = 1;
      swap(items + j, items + j - 1);
      j--;
    }
  }
  
  return changed;
}

int stride_optimise(fas_optimiser *o, size_t n, size_t *data, size_t stride){
  int changed = 0;
  while(n > stride){
    changed |= table_optimise(o, stride, data);
    data += stride;
    n -= stride;
  }
  changed |= table_optimise(o, n, data);
  return changed;
}



int kwik_sort(fas_optimiser *o, size_t n, size_t *data, size_t depth){
  if(n <= 1) return 0;
  if(depth >= 10) return 0;

  size_t *lt = (size_t *)malloc(n * sizeof(size_t));
  size_t *gt = (size_t *)malloc(n * sizeof(size_t));

  size_t ltn = 0;
  size_t gtn = 0;

  size_t pivot = data[random_number(n)];
 
  for(size_t i = 0; i < n; i++){
    int c = tournament_compare(o->_tournament, data[i], pivot);
    if(c < 0) lt[ltn++] = data[i];
    else if(c == 0){
      if(random_number(2)){
        lt[ltn++] = data[i];
      } else {
        gt[gtn++] = data[i];
      }
    }
    else gt[gtn++] = data[i];
  }
  
  depth++;
  kwik_sort(o, ltn, lt, depth);
  kwik_sort(o, gtn, gt, depth);

  memcpy(data, lt, sizeof(size_t) * ltn);
  memcpy(data + ltn, gt, sizeof(size_t) * gtn);

  free(lt);
  free(gt);
  return 1;
}

size_t *copy_items(size_t n, size_t *items){
  size_t *copy = (size_t *)calloc(n, sizeof(size_t));
  memcpy(copy, items, n * sizeof(size_t));
  return copy;
}

population *build_population(fas_optimiser *o,
                             size_t n,
                             size_t *items,
                             size_t ps){
  population *p = population_new(ps, n);

  for(size_t i = 0; i < ps; i++){
    size_t *data = copy_items(n, items);
    kwik_sort(o, n, data, 0), 
    p->members[i].data = data;
    p->members[i].score = score_fas_tournament(o->_tournament, n, data);
  }

  population_heapify(p);
  return p;
}

int coin_flip(){
  return random_number(2);
}

void mutate(fas_optimiser *o, size_t n, size_t *data){
  size_t i = random_number(n);
  size_t j;
  do{ j = random_number(n); } while(i == j);
  if(j < i){
    size_t k = i;
    i = j;
    j = k;
  }
  switch(random_number(5)){
    case 0:
      reverse(data + i, data + j);  
      break;
    case 1: 
      swap(data + i, data + j);  
      break;
    case 2:
      if(coin_flip()){
        move_pointer_right(data + i, j - i);
      } else {
        move_pointer_left(data + j, j - i);
      }
      break;
    case 3:
      if(j > i + 12) j = i + 12;
      table_optimise(o, j - i, data + i);
      break;
    case 4:
      local_sort(o, j - i, data + i);
      break;
  }
}

void improve_population(fas_optimiser *o, population *p, size_t count){
  tournament *t = o->_tournament;
  size_t n = t->size;
  size_t *data = (size_t *)malloc(n * sizeof(size_t));

  for(size_t i = 0; i < count; i++){
    size_t *candidate = p->members[random_number(p->population_count)].data;
    memcpy(data, candidate, n * sizeof(size_t));
    mutate(o, n, data);
    double score = score_fas_tournament(t, t->size, candidate);
    
    if(!population_contains(p, score, data)){
      population_push(p, score, data);
    }
  }

  free(data);
}

void population_optimise(fas_optimiser *o,
                         size_t n,
                         size_t *items,
                         size_t initial_size,
                         size_t generations){
  population *p = build_population(o, n, items, initial_size);
  improve_population(o, p, generations);
  memcpy(items, fittest_member(p).data, n * sizeof(size_t));
  population_del(p);
}

void comprehensive_smoothing(fas_optimiser *o, size_t n, size_t *results){
  stride_optimise(o, n, results, 11); 
  local_sort(o, n, results);
  stride_optimise(o, n, results, 13); 
  local_sort(o, n, results);
  reset_optimiser(o);
   
  for(int i = 0; i < 10; i++){
    int changed = 0;
    changed |= stride_optimise(o, n, results, 12);
    changed |= stride_optimise(o, n, results, 7);
    changed |= local_sort(o, n, results);
    reset_optimiser(o);
    if(!changed) break;
    single_move_optimise(o,n,results);
  } 
}

size_t *optimal_ordering(tournament *t, size_t *results){
  fas_optimiser *o = new_optimiser(t);
  size_t n = t->size;
  if(results == NULL){
    results = integer_range(n);
  }

  if(n <= 15){
    table_optimise(o, n, results);
    del_optimiser(o);
    return results;
  }

  population_optimise(o, n, results, 500, 1000);
  comprehensive_smoothing(o, n, results);
  window_optimise(o, n, results, 10);
  local_sort(o, n, results);

  del_optimiser(o);
  return results;
}

size_t tie_starting_from(tournament *t, size_t n, size_t *items, size_t start_index){
  for(size_t i = start_index+1; i < n; i++){
    for(size_t j = start_index; j < i; j++){
      int c = tournament_compare(t, items[i], items[j]);

      if(c) return i;
    }
  }

  return n;
}

size_t condorcet_boundary_from(tournament *t, size_t n, size_t *items, size_t start_index){
  size_t boundary = start_index;

  int boundary_change = 0;
  do {
    boundary_change = 0;

    for(size_t i = start_index; i <= boundary; i++){
      for(size_t j = boundary + 1; j < n; j++){
        if(tournament_compare(t, items[j], items[i]) <= 0){
          boundary = j;
          boundary_change = 1;
          break; 
        }
      }     
    }
  } while(boundary_change);

  return boundary;
}

//optimisation_table.c
#define MAX_OCCUPANCY_RATIO 0.9
#define DEFAULT_TABLE_SIZE 65536

inline int set_contains_value(size_t length, size_t *xs, size_t x){
  for(size_t i = 0; i < length; i++) if(xs[i] == x) return 1;
  return 0;
}

int set_compare(size_t length, size_t *x, size_t *y){
  for(size_t i = 0; i < length; i++) if(!set_contains_value(length, y, x[i])) return 0;
  return 1;
}

uint64_t hash64(uint64_t key)
{
  key = (~key) + (key << 21);
  key = key ^ (key >> 24);
  key = (key + (key << 3)) + (key << 8);
  key = key ^ (key >> 14);
  key = (key + (key << 2)) + (key << 4);
  key = key ^ (key >> 28);
  key = key + (key << 31);
  return key;
}

uint64_t set_hash(size_t length, size_t *x){
  uint64_t result = 0;
  for(size_t i = 0; i < length; i++) result ^= hash64(x[i]);
  return result;
}

size_t *clone_set(size_t length, size_t *x){
  size_t *result = (size_t *)malloc(length * sizeof(size_t));
  memcpy(result, x, length * sizeof(size_t));
  return result;
}

optimisation_table *optimisation_table_new(){
  optimisation_table *result = (optimisation_table *)malloc(sizeof(optimisation_table));
  result->occupancy = 0;
  result->length=DEFAULT_TABLE_SIZE;
  result->entries = (ot_entry *)calloc(DEFAULT_TABLE_SIZE, sizeof(ot_entry));
  return result;
}

void optimisation_table_del(optimisation_table *ot){
  for(size_t i = 0; i < ot->length; i++) free(ot->entries[i].data);
  free(ot->entries); 
  free(ot);
}

ot_entry *optimisation_table_lookup_internal(optimisation_table *ot, size_t length, size_t *data, int must_copy){
  uint64_t h = set_hash(length, data);

  size_t mask = ot->length - 1;
  size_t p = (size_t)(h & mask);

  while(1){
    ot_entry *ce = ot->entries + p;
    if(!ce->length){
      if(ot->occupancy > ot->length * MAX_OCCUPANCY_RATIO){
        size_t old_length = ot->length;
        ot_entry *old_entries = ot->entries;
        ot->length *= 2;
        ot->entries = (ot_entry *)calloc(ot->length, sizeof(ot_entry));

        for(size_t i = 0; i < old_length; i++){
          if(old_entries[i].length){
            optimisation_table_lookup_internal(ot, old_entries[i].length, old_entries[i].data, 0)->value = old_entries[i].value;
          }
        }
        free(old_entries);
        return optimisation_table_lookup_internal(ot, length, data, must_copy);
      } else {
        ce->length = length;
        ce->hash = h;
        ce->data = (must_copy ? clone_set(length, data) : data);
        ce->value = -1;
        ot->occupancy++;
        return ce;
      }
    } else {
      if((ce->length == length) && (ce->hash == h) && set_compare(length, data, ce->data)) return ce;
    }

    p = (p + 1) & mask;
  }
}

ot_entry *optimisation_table_lookup(optimisation_table *ot, size_t length, size_t *data){
  return optimisation_table_lookup_internal(ot, length, data, 1);
}

//permutations.c
// Permutations of arrays of size_t

void reverse(size_t *s, size_t *e){
	while(s < e){
		swap(s, e);
		s++;
		e--;
	}	
}

// Returns index of first index altered or length if no changes
size_t next_permutation(size_t length, size_t *data){
	if(length <= 1) return length;

	// Guaranteed not to overflow by above
	size_t k = length - 2;

	while(data[k] >= data[k+1]){
		if(k > 0) k--;
		// We are in decreasing order and thus are done.
		else return length;
	}

	// Now we have data[k] < data[k+1]
	// We want to find the largest index l such that data[k] < data[l]
	size_t l = k + 1;

	for(size_t s = l; s < length; s++){
		if(data[k]  < data[s]) l = s;
	}

	swap(data + k, data + l);

	reverse(data + k + 1, data + length - 1);

	return k;
}

inline static size_t saturate(size_t v){
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v |= v >> 32;
	return v;
}

size_t random_number(size_t n){
	size_t mask = saturate(n);

	size_t result;

	for(;;){
		result = rand() & mask;
		if(result < n) return result;
	}
}

void shuffle(size_t length, size_t *data){
	for(size_t k = length - 1; k > 0; k--){
		size_t j = random_number(k+1);
		assert(j <= k);
		swap(data + j, data + k);
	}
}

void generate_shuffled_range(size_t length, size_t *data){
	data[0] = 0;
	for(size_t i = 1; i < length; i++){
		size_t j = random_number(i + 1);
		if(j < i) data[i] = data[j];
		data[j] = i;
	}
}

//population.c
population *population_new(size_t population_count, size_t members_size){
  size_t size = sizeof(population_member) * population_count + sizeof(population);
  population *p = (population *)malloc(size);
  memset(p, '\0', size);
  p->members_size = members_size;
  p->population_count = population_count;
  return p;
}

void population_del(population *p){
  for(size_t i = 0; i < p->population_count; i++) free(p->members[i].data);
  free(p);
}

static void population_swap(population_member *ms, size_t i, size_t j){
  population_member x = ms[i];
  ms[i] = ms[j];
  ms[j] = x;
}

static void bubble_down(population *p, size_t i){
  if(i >= p->population_count) return;

  size_t c1 = 2 * i + 1;
  size_t c2 = 2 * i + 2;


  if(c1 >= p->population_count) return;

  population_member *cs = p->members;
  size_t smallest_child = (c2 >= p->population_count) ? c1 : (cs[c1].score <= cs[c2].score ? c1 : c2);
  if(cs[smallest_child].score < cs[i].score){
    population_swap(cs, i, smallest_child);
    bubble_down(p, smallest_child);
  }
}

static void heapify_from(population *p, size_t i){
  if(i >= p->population_count) return;
  heapify_from(p, 2 * i + 1);
  heapify_from(p, 2 * i + 2);
  bubble_down(p, i);
}

void population_heapify(population *p){
  heapify_from(p, 0);
}

int population_contains_under(population *p, double key, size_t *data, size_t i){
  if(i >= p->population_count) return 0;
  if(key < p->members[i].score) return 0;
  if(memcmp(data, p->members[i].data, p->members_size * sizeof(size_t))) return 1;
  return population_contains_under(p, key, data, 2*i + 1) || population_contains_under(p, key, data, 2*i + 2);
} 

int population_contains(population *p, double key, size_t *data){
  return population_contains_under(p, key, data, 0);
}

population_member fittest_member(population *p){
  population_member *best_member = p->members;

  for(size_t i = 1; i < p->population_count; i++){
    if(p->members[i].score > best_member->score){
      best_member = p->members + i;
    }
  }

  return *best_member;
}

void population_push(population *p, double key, size_t *data){
  p->members[0].score = key;
  memcpy(p->members[0].data, data, p->members_size* sizeof(size_t));
  bubble_down(p, 0);
}

//fas.c
int main(int argc, char **argv){
  srand(time(NULL) ^ getpid());

  enable_fas_tournament_debug(getenv("DEBUG") != NULL);

  FILE *argf = NULL;

  if(argc > 1){
    if(argc > 2){
      fprintf(stderr, "Usage: fas [inputfile]\n");
      exit(1);
    }

    argf = fopen(argv[1], "r");
    if(!argf){
      fprintf(stderr, "Unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
  } else {
    argf = stdin;
  }

  tournament *t = read_tournament(argf);

  size_t n = t->size;
  size_t *items = optimal_ordering(t, NULL);

  printf("%.0f", score_fas_tournament(t, n, items));
  //printf("Optimal ordering:");

  size_t i = 0;
  size_t next_boundary = condorcet_boundary_from(t, n, items, i);

  for(;;){
    size_t next_i = tie_starting_from(t, n, items, i);

    if(next_i > i + 1){
      //printf(" [");
      for(size_t j = i; j < next_i; j++){
        if(j > i) printf(" ");
        printf(" %lu", items[j]);
      }
      //printf("]");
    } else {
      printf(" %lu", items[i]);
    }

    if(next_i == n) break;

    i = next_i;
    if(i > next_boundary){
      //printf(" ||");
      next_boundary = condorcet_boundary_from(t, n, items, i);
    }
  }
  printf("\n");

  free(items);
  del_tournament(t);

  return 0;
}