#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>
#include <cassert>
#include <climits>
using namespace std;

#define MODE 1

#if MODE==1
// https://sites.google.com/site/kareemergawy/useful-reusable-code/munkres-assignment-algorithm

void step_one(vector<vector<int> > &matrix, int n, int& step) {
	int min_in_row;

	for (int r = 0; r < n; r++) {
		min_in_row = matrix[r][0];
		for (int c = 0; c < n; c++)
			if (matrix[r][c] < min_in_row)
				min_in_row = matrix[r][c];
		for (int c = 0; c < n; c++)
			matrix[r][c] -= min_in_row;
	}
	step = 2;
}

void step_two(vector<vector<int> > &matrix, int n, vector<int> &rowCover, vector<int> &colCover, vector<vector<int> > &m,
		int& step) {
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++) {
			if (matrix[r][c] == 0 && rowCover[r] == 0 && colCover[c] == 0) {
				m[r][c] = 1;
				rowCover[r] = 1;
				colCover[c] = 1;
			}
		}
	for (int r = 0; r < n; r++)
		rowCover[r] = 0;
	for (int c = 0; c < n; c++)
		colCover[c] = 0;
	step = 3;
}

void step_three(int n, vector<int> &colCover, vector<vector<int> > & m, int& step) {
	int colcount;
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			if (m[r][c] == 1)
				colCover[c] = 1;

	colcount = 0;
	for (int c = 0; c < n; c++)
		if (colCover[c] == 1)
			colcount += 1;
	if (colcount >= n || colcount >= n)
		step = 7;
	else
		step = 4;
}

void find_a_zero(vector<vector<int> > &matrix, int n, vector<int> &rowCover, vector<int> &colCover, int& row,
		int& col) {
	int r = 0;
	int c;
	bool done;
	row = -1;
	col = -1;
	done = false;
	while (!done) {
		c = 0;
		while (true) {
			if (matrix[r][c] == 0 && rowCover[r] == 0 && colCover[c] == 0) {
				row = r;
				col = c;
				done = true;
			}
			c += 1;
			if (c >= n || done)
				break;
		}
		r += 1;
		if (r >= n)
			done = true;
	}
}

bool star_in_row(vector<vector<int> > &m, int n, int row) {
	bool tmp = false;
	for (int c = 0; c < n; c++)
		if (m[row][c] == 1)
			tmp = true;
	return tmp;
}

void find_star_in_row(vector<vector<int> > &m, int n, int row, int& col) {
	col = -1;
	for (int c = 0; c < n; c++)
		if (m[row][c] == 1)
			col = c;
}

void step_four(vector<vector<int> > &matrix, int n, vector<int> &rowCover, vector<int> &colCover, vector<vector<int> > &m,
		int& path_row_0, int& path_col_0, int& step) {
	int row = -1;
	int col = -1;
	bool done;

	done = false;
	while (!done) {
		find_a_zero(matrix, n, rowCover, colCover, row, col);
		if (row == -1) {
			done = true;
			step = 6;
		} else {
			m[row][col] = 2;
			if (star_in_row(m, n, row)) {
				find_star_in_row(m, n, row, col);
				rowCover[row] = 1;
				colCover[col] = 0;
			} else {
				done = true;
				step = 5;
				path_row_0 = row;
				path_col_0 = col;
			}
		}
	}
}

void find_star_in_col(int n, vector<vector<int> > &m, int c, int& r) {
	r = -1;
	for (int i = 0; i < n; i++)
		if (m[i][c] == 1)
			r = i;
}

void find_prime_in_row(int n, vector<vector<int> > &m, int r, int& c) {
	for (int j = 0; j < n; j++)
		if (m[r][j] == 2)
			c = j;
}

void augment_path(vector<vector<int> > &m, int path_count, vector<vector<int> > &path) {
	for (int p = 0; p < path_count; p++)
		if (m[path[p][0]][path[p][1]] == 1)
			m[path[p][0]][path[p][1]] = 0;
		else
			m[path[p][0]][path[p][1]] = 1;
}

void clear_covers(int n, vector<int> &rowCover, vector<int> &colCover) {
	for (int r = 0; r < n; r++)
		rowCover[r] = 0;
	for (int c = 0; c < n; c++)
		colCover[c] = 0;
}

void erase_primes(int n, vector<vector<int> > &m) {
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			if (m[r][c] == 2)
				m[r][c] = 0;
}

void step_five(int n, vector<int> &rowCover, vector<int> &colCover, vector<vector<int> > &m, int& path_row_0,
		int& path_col_0, int& path_count, vector<vector<int> > &path, int& step) {
	bool done;
	int r = -1;
	int c = -1;

	path_count = 1;
	path[path_count - 1][0] = path_row_0;
	path[path_count - 1][1] = path_col_0;
	done = false;
	while (!done) {
		find_star_in_col(n, m, path[path_count - 1][1], r);
		if (r > -1) {
			path_count += 1;
			path[path_count - 1][0] = r;
			path[path_count - 1][1] = path[path_count - 2][1];
		} else
			done = true;
		if (!done) {
			find_prime_in_row(n, m, path[path_count - 1][0], c);
			path_count += 1;
			path[path_count - 1][0] = path[path_count - 2][0];
			path[path_count - 1][1] = c;
		}
	}
	augment_path(m, path_count, path);
	clear_covers(n, rowCover, colCover);
	erase_primes(n, m);
	step = 3;
}

void find_smallest(vector<vector<int> > &matrix, int n, vector<int> &rowCover, vector<int> &colCover,
		int& minval) {
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			if (rowCover[r] == 0 && colCover[c] == 0)
				if (minval > matrix[r][c])
					minval = matrix[r][c];
}

void step_six(vector<vector<int> > &matrix, int n, vector<int> &rowCover, vector<int> &colCover, int& step) {
	int minval = INT_MAX;
	find_smallest(matrix, n, rowCover, colCover, minval);
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++) {
			if (rowCover[r] == 1)
				matrix[r][c] += minval;
			if (colCover[c] == 0)
				matrix[r][c] -= minval;
		}
	step = 4;
}

void runMunkers(vector<vector<int> > &matrix, vector<vector<int> > &m, int n, bool max) {

	if (max == true) {
		int maxValue = matrix[0][0];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] > maxValue) {
					maxValue = matrix[i][j];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = maxValue - matrix[i][j];
			}
		}
	}

	bool done = false;
	int step = 1;
	vector<int> rowCover(n);
	vector<int> colCover(n);
	int path_row_0 = 0;
	int path_col_0 = 0;
	int path_count = 0;
	for (int i = 0; i < n; i++) {
		rowCover[i] = colCover[i] = 0;
		for (int j = 0; j < n; j++) {
			m[i][j] = 0;
		}
	}
	vector<vector<int> > path(n*2);
	for (int i = 0; i < n * 2; i++) {
		path[i].resize(2);
	}
	while (!done) {
/*
		cout << "Matrix: " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "Mask: " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << m[i][j] << " ";
			}
			cout << endl;
		}
*/
		switch (step) {
		case 1:
			step_one(matrix, n, step);
			break;
		case 2:
			step_two(matrix, n, rowCover, colCover, m, step);
			break;
		case 3:
			step_three(n, colCover, m, step);
			break;
		case 4:
			step_four(matrix, n, rowCover, colCover, m, path_row_0, path_col_0,
					step);
			break;
		case 5:
			step_five(n, rowCover, colCover, m, path_row_0, path_col_0,
					path_count, path, step);
			break;
		case 6:
			step_six(matrix, n, rowCover, colCover, step);
			break;
		case 7:
			done = true;
			break;
		}
	}
}
#elif MODE==2
// https://github.com/saebyn/munkres-cpp

/*
 *   Copyright (c) 2007 John Weaver
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */

template <class T>
class Matrix {
public:
  Matrix();
  Matrix(unsigned int rows, unsigned int columns);
  Matrix(std::initializer_list<std::initializer_list<T>> init);
  Matrix(const Matrix<T> &other);
  Matrix<T> & operator= (const Matrix<T> &other);
  ~Matrix();
  // all operations modify the matrix in-place.
  void resize(unsigned int rows, unsigned int columns, T default_value = 0);
  void clear(void);
  T& operator () (unsigned int x, unsigned int y);
  const T& operator () (unsigned int x, unsigned int y) const;
  const T min() const;
  const T max() const;
  inline unsigned int minsize(void) {
    return ((m_rows < m_columns) ? m_rows : m_columns);
  }
  inline unsigned int columns(void) const {
    return m_columns;
  }
  inline unsigned int rows(void) const {
    return m_rows;
  }
private:
  T **m_matrix;
  unsigned int m_rows;
  unsigned int m_columns;
};

/*export*/ template <class T>
Matrix<T>::Matrix() {
  m_rows = 0;
  m_columns = 0;
  m_matrix = NULL;
}


/*export*/ template <class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> init) {
  m_matrix = NULL;
  m_rows = init.size();
  if ( m_rows == 0 ) {
    m_columns = 0;
  } else {
    m_columns = init.begin()->size();
    if ( m_columns > 0 ) {
      resize(m_rows, m_columns);
    }
  }

  int i = 0, j;
  for ( auto row = init.begin() ; row != init.end() ; ++row, ++i ) {
    assert ( row->size() == m_columns && "All rows must have the same number of columns." );
    j = 0;
    for ( auto value = row->begin() ; value != row->end() ; ++value, ++j ) {
      m_matrix[i][j] = *value;
    }
  }
}

/*export*/ template <class T>
Matrix<T>::Matrix(const Matrix<T> &other) {
  if ( other.m_matrix != NULL ) {
    // copy arrays
    m_matrix = NULL;
    resize(other.m_rows, other.m_columns);
    for ( unsigned int i = 0 ; i < m_rows ; i++ ) {
      for ( unsigned int j = 0 ; j < m_columns ; j++ ) {
        m_matrix[i][j] = other.m_matrix[i][j];
      }
    }
  } else {
    m_matrix = NULL;
    m_rows = 0;
    m_columns = 0;
  }
}

/*export*/ template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns) {
  m_matrix = NULL;
  resize(rows, columns);
}

/*export*/ template <class T>
Matrix<T> &
Matrix<T>::operator= (const Matrix<T> &other) {
  if ( other.m_matrix != NULL ) {
    // copy arrays
    resize(other.m_rows, other.m_columns);
    for ( unsigned int i = 0 ; i < m_rows ; i++ ) {
      for ( unsigned int j = 0 ; j < m_columns ; j++ ) {
          m_matrix[i][j] = other.m_matrix[i][j];
      }
    }
  } else {
    // free arrays
    for ( unsigned int i = 0 ; i < m_columns ; i++ ) {
      delete [] m_matrix[i];
    }

    delete [] m_matrix;

    m_matrix = NULL;
    m_rows = 0;
    m_columns = 0;
  }
  
  return *this;
}

/*export*/ template <class T>
Matrix<T>::~Matrix() {
  if ( m_matrix != NULL ) {
    // free arrays
    for ( unsigned int i = 0 ; i < m_rows ; i++ ) {
      delete [] m_matrix[i];
    }

    delete [] m_matrix;
  }
  m_matrix = NULL;
}

/*export*/ template <class T>
void
Matrix<T>::resize(unsigned int rows, unsigned int columns, T default_value) {
  assert ( rows > 0 && columns > 0 && "Columns and rows must exist." );

  if ( m_matrix == NULL ) {
    // alloc arrays
    m_matrix = new T*[rows]; // rows
    for ( unsigned int i = 0 ; i < rows ; i++ ) {
      m_matrix[i] = new T[columns]; // columns
    }

    m_rows = rows;
    m_columns = columns;
    clear();
  } else {
    // save array pointer
    T **new_matrix;
    // alloc new arrays
    new_matrix = new T*[rows]; // rows
    for ( unsigned int i = 0 ; i < rows ; i++ ) {
      new_matrix[i] = new T[columns]; // columns
      for ( unsigned int j = 0 ; j < columns ; j++ ) {
        new_matrix[i][j] = default_value;
      }
    }

    // copy data from saved pointer to new arrays
    unsigned int minrows = std::min<unsigned int>(rows, m_rows);
    unsigned int mincols = std::min<unsigned int>(columns, m_columns);
    for ( unsigned int x = 0 ; x < minrows ; x++ ) {
      for ( unsigned int y = 0 ; y < mincols ; y++ ) {
        new_matrix[x][y] = m_matrix[x][y];
      }
    }

    // delete old arrays
    if ( m_matrix != NULL ) {
      for ( unsigned int i = 0 ; i < m_rows ; i++ ) {
        delete [] m_matrix[i];
      }

      delete [] m_matrix;
    }

    m_matrix = new_matrix;
  }

  m_rows = rows;
  m_columns = columns;
}

/*export*/ template <class T>
void
Matrix<T>::clear() {
  assert( m_matrix != NULL );

  for ( unsigned int i = 0 ; i < m_rows ; i++ ) {
    for ( unsigned int j = 0 ; j < m_columns ; j++ ) {
      m_matrix[i][j] = 0;
    }
  }
}

/*export*/ template <class T>
inline T&
Matrix<T>::operator ()(unsigned int x, unsigned int y) {
  assert ( x < m_rows );
  assert ( y < m_columns );
  assert ( m_matrix != NULL );
  return m_matrix[x][y];
}


/*export*/ template <class T>
inline const T&
Matrix<T>::operator ()(unsigned int x, unsigned int y) const {
  assert ( x < m_rows );
  assert ( y < m_columns );
  assert ( m_matrix != NULL );
  return m_matrix[x][y];
}


/*export*/ template <class T>
const T
Matrix<T>::min() const {
  assert( m_matrix != NULL );
  assert ( m_rows > 0 );
  assert ( m_columns > 0 );
  T min = m_matrix[0][0];

  for ( unsigned int i = 0 ; i < m_rows ; i++ ) {
    for ( unsigned int j = 0 ; j < m_columns ; j++ ) {
      min = std::min<T>(min, m_matrix[i][j]);
    }
  }

  return min;
}


/*export*/ template <class T>
const T
Matrix<T>::max() const {
  assert( m_matrix != NULL );
  assert ( m_rows > 0 );
  assert ( m_columns > 0 );
  T max = m_matrix[0][0];

  for ( unsigned int i = 0 ; i < m_rows ; i++ ) {
    for ( unsigned int j = 0 ; j < m_columns ; j++ ) {
      max = std::max<T>(max, m_matrix[i][j]);
    }
  }

  return max;
}

class Munkres {
public:
  void solve(Matrix<double> &m);
private:
  static const int NORMAL = 0;
  static const int STAR = 1;
  static const int PRIME = 2; 
  inline bool find_uncovered_in_matrix(double, unsigned int&, unsigned int&) const;
  inline bool pair_in_list(const std::pair<int,int> &, const std::list<std::pair<int,int> > &);
  int step1(void);
  int step2(void);
  int step3(void);
  int step4(void);
  int step5(void);
  int step6(void);

  Matrix<int> mask_matrix;
  Matrix<double> matrix;
  bool *row_mask;
  bool *col_mask;
  unsigned int saverow, savecol;
};

void
replace_infinites(Matrix<double> &matrix) {
  const unsigned int rows = matrix.rows(),
                     columns = matrix.columns();
  assert( rows > 0 && columns > 0 );
  double max = matrix(0, 0);
  const auto infinity = std::numeric_limits<double>::infinity();

  // Find the greatest value in the matrix that isn't infinity.
  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    for ( unsigned int col = 0 ; col < columns ; col++ ) {
      if ( matrix(row, col) != infinity ) {
        if ( max == infinity ) {
          max = matrix(row, col);
        } else {
          max = std::max<double>(max, matrix(row, col));
        }
      }
    }
  }

  // a value higher than the maximum value present in the matrix.
  if ( max == infinity ) {
    // This case only occurs when all values are infinite.
    max = 0;
  } else {
    max++;
  }
  
  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    for ( unsigned int col = 0 ; col < columns ; col++ ) {
      if ( matrix(row, col) == infinity ) {
        matrix(row, col) = max;
      }
    }
  }

}

void 
minimize_along_direction(Matrix<double> &matrix, bool over_columns) {
  const unsigned int outer_size = over_columns ? matrix.columns() : matrix.rows(),
                     inner_size = over_columns ? matrix.rows() : matrix.columns();

  // Look for a minimum value to subtract from all values along
  // the "outer" direction.
  for ( unsigned int i = 0 ; i < outer_size ; i++ ) {
    double min = over_columns ? matrix(0, i) : matrix(i, 0);

    // As long as the current minimum is greater than zero,
    // keep looking for the minimum.
    // Start at one because we already have the 0th value in min.
    for ( unsigned int j = 1 ; j < inner_size && min > 0 ; j++ ) {
      min = std::min<double>(
        min,
        over_columns ? matrix(j, i) : matrix(i, j));
    }

    if ( min > 0 ) {
      for ( unsigned int j = 0 ; j < inner_size ; j++ ) {
        if ( over_columns ) {
          matrix(j, i) -= min;
        } else {
          matrix(i, j) -= min;
        }
      }
    }
  }
}


bool 
Munkres::find_uncovered_in_matrix(double item, unsigned int &row, unsigned int &col) const {
  unsigned int rows = matrix.rows(),
               columns = matrix.columns();

  for ( row = 0 ; row < rows ; row++ ) {
    if ( !row_mask[row] ) {
      for ( col = 0 ; col < columns ; col++ ) {
        if ( !col_mask[col] ) {
          if ( matrix(row,col) == item ) {
            return true;
          }
        }
      }
    }
  }

  return false;
}

bool 
Munkres::pair_in_list(const std::pair<int,int> &needle, const std::list<std::pair<int,int> > &haystack) {
  for ( std::list<std::pair<int,int> >::const_iterator i = haystack.begin() ; i != haystack.end() ; i++ ) {
    if ( needle == *i ) {
      return true;
    }
  }
  
  return false;
}

int 
Munkres::step1(void) {
  const unsigned int rows = matrix.rows(),
                     columns = matrix.columns();

  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    for ( unsigned int col = 0 ; col < columns ; col++ ) {
      if ( 0 == matrix(row, col) ) {
        bool isstarred = false;
        for ( unsigned int nrow = 0 ; nrow < rows ; nrow++ )
          if ( STAR == mask_matrix(nrow,col) ) {
            isstarred = true;
            break;
          }

        if ( !isstarred ) {
          for ( unsigned int ncol = 0 ; ncol < columns ; ncol++ )
            if ( STAR == mask_matrix(row, ncol) ) {
              isstarred = true;
              break;
            }
        }
              
        if ( !isstarred ) {
          mask_matrix(row,col) = STAR;
        }
      }
    }
  }

  return 2;
}

int 
Munkres::step2(void) {
  const unsigned int rows = matrix.rows(),
                     columns = matrix.columns();
  unsigned int covercount = 0;

  for ( unsigned int row = 0 ; row < rows ; row++ )
    for ( unsigned int col = 0 ; col < columns ; col++ )
      if ( STAR == mask_matrix(row, col) ) {
        col_mask[col] = true;
        covercount++;
      }
      
  if ( covercount >= matrix.minsize() ) {
#ifdef DEBUG
    std::cout << "Final cover count: " << covercount << std::endl;
#endif
    return 0;
  }

#ifdef DEBUG
  std::cout << "Munkres matrix has " << covercount << " of " << matrix.minsize() << " Columns covered:" << std::endl;
  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    for ( unsigned int col = 0 ; col < columns ; col++ ) {
      std::cout.width(8);
      std::cout << matrix(row, col) << ",";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
#endif


  return 3;
}

int 
Munkres::step3(void) {
  /*
  Main Zero Search

   1. Find an uncovered Z in the distance matrix and prime it. If no such zero exists, go to Step 5
   2. If No Z* exists in the row of the Z', go to Step 4.
   3. If a Z* exists, cover this row and uncover the column of the Z*. Return to Step 3.1 to find a new Z
  */
  if ( find_uncovered_in_matrix(0, saverow, savecol) ) {
    mask_matrix(saverow,savecol) = PRIME; // prime it.
  } else {
    return 5;
  }

  for ( unsigned int ncol = 0 ; ncol < matrix.columns() ; ncol++ ) {
    if ( mask_matrix(saverow,ncol) == STAR ) {
      row_mask[saverow] = true; //cover this row and
      col_mask[ncol] = false; // uncover the column containing the starred zero
      return 3; // repeat
    }
  }

  return 4; // no starred zero in the row containing this primed zero
}

int 
Munkres::step4(void) {
  const unsigned int rows = matrix.rows(),
                     columns = matrix.columns();

  // seq contains pairs of row/column values where we have found
  // either a star or a prime that is part of the ``alternating sequence``.
  std::list<std::pair<int,int> > seq;
  // use saverow, savecol from step 3.
  std::pair<int,int> z0(saverow, savecol);
  seq.insert(seq.end(), z0);

  // We have to find these two pairs:
  std::pair<int,int> z1(-1, -1);
  std::pair<int,int> z2n(-1, -1);

  unsigned int row, col = savecol;
  /*
  Increment Set of Starred Zeros

   1. Construct the ``alternating sequence'' of primed and starred zeros:

         Z0 : Unpaired Z' from Step 4.2 
         Z1 : The Z* in the column of Z0
         Z[2N] : The Z' in the row of Z[2N-1], if such a zero exists 
         Z[2N+1] : The Z* in the column of Z[2N]

      The sequence eventually terminates with an unpaired Z' = Z[2N] for some N.
  */
  bool madepair;
  do {
    madepair = false;
    for ( row = 0 ; row < rows ; row++ ) {
      if ( mask_matrix(row,col) == STAR ) {
        z1.first = row;
        z1.second = col;
        if ( pair_in_list(z1, seq) ) {
          continue;
        }
        
        madepair = true;
        seq.insert(seq.end(), z1);
        break;
      }
    }

    if ( !madepair )
      break;

    madepair = false;

    for ( col = 0 ; col < columns ; col++ ) {
      if ( mask_matrix(row, col) == PRIME ) {
        z2n.first = row;
        z2n.second = col;
        if ( pair_in_list(z2n, seq) ) {
          continue;
        }
        madepair = true;
        seq.insert(seq.end(), z2n);
        break;
      }
    }
  } while ( madepair );

  for ( std::list<std::pair<int,int> >::iterator i = seq.begin() ;
      i != seq.end() ;
      i++ ) {
    // 2. Unstar each starred zero of the sequence.
    if ( mask_matrix(i->first,i->second) == STAR )
      mask_matrix(i->first,i->second) = NORMAL;

    // 3. Star each primed zero of the sequence,
    // thus increasing the number of starred zeros by one.
    if ( mask_matrix(i->first,i->second) == PRIME )
      mask_matrix(i->first,i->second) = STAR;
  }

  // 4. Erase all primes, uncover all columns and rows, 
  for ( unsigned int row = 0 ; row < mask_matrix.rows() ; row++ ) {
    for ( unsigned int col = 0 ; col < mask_matrix.columns() ; col++ ) {
      if ( mask_matrix(row,col) == PRIME ) {
        mask_matrix(row,col) = NORMAL;
      }
    }
  }
  
  for ( unsigned int i = 0 ; i < rows ; i++ ) {
    row_mask[i] = false;
  }

  for ( unsigned int i = 0 ; i < columns ; i++ ) {
    col_mask[i] = false;
  }

  // and return to Step 2. 
  return 2;
}

int 
Munkres::step5(void) {
  const unsigned int rows = matrix.rows(),
                     columns = matrix.columns();
  /*
  New Zero Manufactures

   1. Let h be the smallest uncovered entry in the (modified) distance matrix.
   2. Add h to all covered rows.
   3. Subtract h from all uncovered columns
   4. Return to Step 3, without altering stars, primes, or covers. 
  */
  double h = 0;
  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    if ( !row_mask[row] ) {
      for ( unsigned int col = 0 ; col < columns ; col++ ) {
        if ( !col_mask[col] ) {
          if ( (h > matrix(row, col) && matrix(row, col) != 0) || h == 0 ) {
            h = matrix(row, col);
          }
        }
      }
    }
  }

  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    if ( row_mask[row] ) {
      for ( unsigned int col = 0 ; col < columns ; col++ ) {
        matrix(row, col) += h;
      }
    }
  }
  
  for ( unsigned int col = 0 ; col < columns ; col++ ) {
    if ( !col_mask[col] ) {
      for ( unsigned int row = 0 ; row < rows ; row++ ) {
        matrix(row, col) -= h;
      }
    }
  }

  return 3;
}

/*
 *
 * Linear assignment problem solution
 * [modifies matrix in-place.]
 * matrix(row,col): row major format assumed.
 *
 * Assignments are remaining 0 values
 * (extra 0 values are replaced with -1)
 *
 */
void 
Munkres::solve(Matrix<double> &m) {
  const unsigned int rows = m.rows(),
                     columns = m.columns(),
                     size = std::max<unsigned int>(rows, columns);

#ifdef DEBUG
  std::cout << "Munkres input matrix:" << std::endl;
  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    for ( unsigned int col = 0 ; col < columns ; col++ ) {
      std::cout.width(8);
      std::cout << m(row, col) << ",";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
#endif

  bool notdone = true;
  int step = 1;

  // Copy input matrix
  this->matrix = m;

  if ( rows != columns ) {
    // If the input matrix isn't square, make it square
    // and fill the empty values with the largest value present
    // in the matrix.
    matrix.resize(size, size, matrix.max());
  }


  // STAR == 1 == starred, PRIME == 2 == primed
  mask_matrix.resize(size, size);

  row_mask = new bool[size];
  col_mask = new bool[columns];
  for ( unsigned int i = 0 ; i < size ; i++ ) {
    row_mask[i] = false;
  }

  for ( unsigned int i = 0 ; i < size ; i++ ) {
    col_mask[i] = false;
  }

  // Prepare the matrix values...

  // If there were any infinities, replace them with a value greater
  // than the maximum value in the matrix.
  replace_infinites(matrix);

  minimize_along_direction(matrix, false);
  minimize_along_direction(matrix, true);

  // Follow the steps
  while ( notdone ) {
    switch ( step ) {
      case 0:
        notdone = false;
        // end the step flow
        break;
      case 1:
        step = step1();
        // step is always 2
        break;
      case 2:
        step = step2();
        // step is always either 0 or 3
        break;
      case 3:
        step = step3();
        // step in [3, 4, 5]
        break;
      case 4:
        step = step4();
        // step is always 2
        break;
      case 5:
        step = step5();
        // step is always 3
        break;
    }
  }

  // Store results
  for ( unsigned int row = 0 ; row < size ; row++ ) {
    for ( unsigned int col = 0 ; col < size ; col++ ) {
      if ( mask_matrix(row, col) == STAR ) {
        matrix(row, col) = 0;
      } else {
        matrix(row, col) = -1;
      }
    }
  }

#ifdef DEBUG
  std::cout << "Munkres output matrix:" << std::endl;
  for ( unsigned int row = 0 ; row < rows ; row++ ) {
    for ( unsigned int col = 0 ; col < columns ; col++ ) {
      std::cout.width(1);
      std::cout << matrix(row, col) << ",";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
#endif


  // Remove the excess rows or columns that we added to fit the
  // input to a square matrix.
  matrix.resize(rows, columns);

  m = matrix;

  delete [] row_mask;
  delete [] col_mask;
}
#endif

/* code below is my own code (public domain) */
vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		//if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		//}
		str = str.substr(cutAt + 1);
	}
	//if(str.length() > 0){
		result.push_back(str);
	//}
	return result;
}

int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string line;
	for(;getline(cin,line);){
		vector<pair<int,int> > customers_int;
		vector<int> products_int;
		{
			vector<string>a=split(line,";");
			if(a[0]=="" || a[1]==""){puts("0.00");continue;}
			vector<string>customers=split(a[0],",");
			for(auto it=customers.begin();it!=customers.end();++it){
				int total=0,vowels=0;
				for(int i=0;i<it->size();i++){
					int c=it->at(i);
					if(('A'<=c&&c<='Z')||('a'<=c&&c<='z'))total++;
					if(strchr("AaEeIiOoUuYy",c))vowels++;
				}
				customers_int.push_back(make_pair(total,vowels));
			}
			vector<string>products=split(a[1],",");
			for(auto it=products.begin();it!=products.end();++it){
				int total=0;//,vowels=0;
				for(int i=0;i<it->size();i++){
					int c=it->at(i);
					if(('A'<=c&&c<='Z')||('a'<=c&&c<='z'))total++;
					//if(strchr("AaEeIiOoUuYy",c))vowels++;
				}
				products_int.push_back(total);
			}
		}
		int ma=max(customers_int.size(),products_int.size());
		vector<vector<int> > v(ma);
#if MODE==1
		vector<vector<int> > v2(ma);
		vector<vector<int> > as(ma);
#elif MODE==2
		Matrix<double> mat(ma,ma);
#endif
		for(int i=0;i<ma;i++){
			v[i].resize(ma);
#if MODE==1
			v2[i].resize(ma);
			as[i].resize(ma);
#endif
			if(i<customers_int.size()){
				for(int j=0;j<products_int.size();j++){
					int mul=gcd(customers_int[i].first,products_int[j])>1 ? 3 : 2;
					int val=-mul*(
						products_int[j]%2==0 ?
							customers_int[i].second*3 :
							(customers_int[i].first-customers_int[i].second)*2
					);
					v[i][j]=val;
#if MODE==1
					v2[i][j]=val;
#elif MODE==2
					mat(i,j)=val;
#endif
				}
			}
		}
#if MODE==1
		runMunkers(v,as,ma,false);
#elif MODE==2
		Munkres m;
		m.solve(mat);
#endif
		double ret=0;
		for(int i=0;i<customers_int.size();i++){
			for(int j=0;j<products_int.size();j++){
#if MODE==1
				if(as[i][j]==1)ret+=-v2[i][j]/4.0;
#elif MODE==2
				if(mat(i,j)==0)ret+=-v[i][j]/4.0;
#endif
			}
		}
		printf("%.2f\n",ret);
	}
}