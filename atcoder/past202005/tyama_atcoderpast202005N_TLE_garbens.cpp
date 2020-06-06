#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

namespace exp_gerbens {

template <typename T>
void BranchlessSwap(T* arr, size_t a, size_t b) {
  auto x = arr[a];
  auto y = arr[b];
  if (y < x) std::swap(x, y);
  arr[a] = x; arr[b] = y;
}

// BubbleSort works better it has N(N-1)/2 stores, but x is updated in the inner
// loop. This is cmp/cmov sequence making the inner loop 2 cycles.
template <typename T>
void BubbleSort(T* arr, size_t n) {
  for (size_t i = n; i > 1; i--) {
    auto x = arr[0];
    for (size_t j = 1; j < i; j++) {
      auto y = arr[j];
      arr[j - 1] = (x <= y ? x : y);
      x = (x <= y ? y : x);
    }
    arr[i - 1] = x;
  }
}

// BubbleSort2 bubbles two elements at a time. This means it's doing N(N+1)/4
// iterations and therefore much less stores. Correctly ordering the cmov's it
// is still possible to execute the inner loop in 2 cycles with respect to
// data dependencies. So in effect this cuts running time by 2x, even though
// it's not cutting number of comparisons.
template <typename T>
void BubbleSort2(T* arr, size_t n) {
  for (size_t i = n; i > 1; i -= 2) {
    auto x = arr[0];
    auto y = arr[1];
    if (y < x) std::swap(x, y);
    for (size_t j = 2; j < i; j++) {
      auto z = arr[j];
      auto w = y <= z ? y : z;
      y = y <= z ? z : y;
      arr[j - 2] = (x <= z ? x : z);
      x = x <= z ? w : x;
    }
    arr[i - 2] = x;
    arr[i - 1] = y;
  }
}

template <typename T>
void SmallSort(T* arr, size_t n) {
  BubbleSort2(arr, n);
}

#if 0
template <typename T>
T* PartitionInto(const T* in, T pivot, T* scratch,
                    size_t scratch_size) {
  size_t larger = scratch_size;
  auto left = scratch;
  auto diff = in - left;
  auto right = scratch + scratch_size;
  while (left < right) {
    auto x = left[diff];
    bool is_larger = x >= pivot;
    auto dest = is_larger ? scratch + scratch_size - 1 : left;
    dest[larger - scratch_size] = x;
    left++;
    larger -= is_larger;
    //if (larger == 0) break;
  }
  return left - (scratch_size - larger);
}
template <typename T>
size_t PartitionInto(T* arr, size_t n, T* out) {
  auto pivot = arr[n - 1];
  auto res = PartitionInto(arr, pivot, out, n - 1);
  out[n - 1] = *res;
  *res = pivot;
  return res - out;
}
#else
template <typename T>
size_t PartitionInto(T* arr, size_t n, T* out) {
  auto pivot = arr[n - 1];
  auto last = out + n - 1;
  for (ptrdiff_t i = -(n - 1); i < 0; i++) {
    auto x = arr[i + n - 1];
    bool is_larger = x >= pivot;
    auto dest = is_larger ? 0 : i;
    last[dest] = x;
    last -= is_larger;
  }
  *last = pivot;
  return last - out;
}
#endif

template <typename T>
void QuickSortScratch(T* arr, size_t n, T* scratch);

template <typename T>
void MedianOfThree(T* arr, size_t n) {
  BranchlessSwap(arr, 0, n / 2);
  BranchlessSwap(arr, 0, n - 1);
  BranchlessSwap(arr, n - 1, n / 2);
}

constexpr size_t kSmallSortThreshold = 16;

template <typename T>
void QuickSortInto(T* arr, size_t n, T* out) {
  if (n > kSmallSortThreshold) {
    MedianOfThree(arr, n);
    auto p = PartitionInto(arr, n, out);
    QuickSortScratch(out, p, arr);
    QuickSortScratch(out + p + 1, n - p - 1, arr);
  } else {
    SmallSort(arr, n);
    for (size_t i = 0; i < n; i++) out[i] = arr[i];
  }
}

template <typename T>
void QuickSortScratch(T* arr, size_t n, T* scratch) {
  if (n > kSmallSortThreshold) {
    MedianOfThree(arr, n);
    auto p = PartitionInto(arr, n, scratch);
    QuickSortInto(scratch, p, arr);
    arr[p] = scratch[p];
    QuickSortInto(scratch + p + 1, n - p - 1, arr + p + 1);
  } else {
    SmallSort(arr, n);
  }
}

template <typename T>
T* DistributeForward(T* left, T* right, T pivot, T* scratch,
                    size_t scratch_size) {
  size_t larger = scratch_size;
  while (left < right) {
    auto x = *left;
    bool is_larger = x >= pivot;
    auto dest = is_larger ? scratch + scratch_size - 1 : left;
    dest[larger - scratch_size] = x;
    left++;
    larger -= is_larger;
    if (larger == 0) break;
  }
  return left - (scratch_size - larger);
}

template <typename T>
T* DistributeBackward(T* left, T* right, T pivot, T* scratch,
                     size_t scratch_size) {
  ptrdiff_t smaller = -scratch_size;
  while (left < right) {
    auto x = right[-1];
    bool is_smaller = x < pivot;
    auto dest = is_smaller ? scratch : right - 1;
    dest[smaller + scratch_size] = x;
    right--;
    smaller += is_smaller;
    if (smaller == 0) break;
  }
  return right + (scratch_size + smaller);
}

// New partition algorithm. It's a branch "reduced" hybrid between Hoare and
// a simplified Lomuto partitioning schemes. Lomuto partitioning works by
// ensuring that the first part of the array is properly partitioned with
// respect to the pivot and grow it by the next element, swapping if needed. Now
// obviously you also have a reverse Lomuto partitioning scheme that works
// backwards, mutatis mutandis. Hoare's algorithm is more symmetrical as it
// starts from both ends, working inwards while swapping elements.  Lomuto's
// scheme can be implemented branch free but has the overhead of doing two
// stores per iteration necessary for branchless implementation of swap.
// Furthermore it runs into the problem that the load at the partition index
// potentially depends on previous stores, which quickly disable CPU load store
// reordering.
//
// We can weaken Lomuto partioning scheme by unconditionally storing elements in
// one of two buckets. This is not so much partitioning as it is distributing.
// The algorithm distributes the elements over the two buckets based on the
// pivot. This is much simpler and cheaper. The bucket containing the elements
// smaller than the pivot can overlap with the array, however we need a
// temporary buffer to hold the other elements. At the end we can copy the
// elements of the temporary buffer to the end of the array to achieve a
// partition. Note this would lead to a stable quicksort. Unfortunately such an
// algorithm would not be in-place as it needs O(n) additional memory.

// Let's call this distribution algorithm L', just like Lomuto there is a
// reverse version of it as well. If we make our temporary buffer a small fixed
// size buffer, we have to terminate the distributing when the fixed buffer is
// full, at which point only a part of the array will have been processed.
// Luckily we can leverage a modified version of Hoare's algorithm. Applying L'
// backward with another tempory buffer with the same fixed size, will terminate
// with that buffer full. Now there is enough space in the array to swap the
// temporary buffers with their proper place in the array. What we are getting
// is a tunable Hoare algorithm that works bulkwise, in the limiting case the
// temporary buffers are of size 1, we recover the original Hoare algorithm.
//
// This scheme greatly improves on branchless Lomuto partioning by reducing the
// amount of work that needs to be done in the inner loop and it greatly
// improves on Hoare algorithm by only hitting branch misses every N elements
// and swapping elements wholesale.
template <size_t kScratchSize, typename T>
size_t PartitionImpl(T pivot, T* arr, size_t n, T* scratch) {
  auto left = arr;
  auto right = arr + n;
  auto pleft = DistributeForward(left, right, pivot, scratch, kScratchSize);
  if (right - pleft <= static_cast<ptrdiff_t>(kScratchSize)) {
    auto size = right - pleft;
    std::memcpy(pleft, scratch + kScratchSize - size, size * sizeof(T));
    return pleft - arr;
  }
  left = pleft + kScratchSize;
  T* res;
  while (true) {
    right = DistributeBackward(left, right, pivot, left - kScratchSize, kScratchSize) - kScratchSize;
    if (right <= left) {
      res = right;
      break;
    }
    left = DistributeForward(left, right, pivot, right, kScratchSize) + kScratchSize;
    if (right <= left) {
      res = left - kScratchSize;
      break;
    }
  }
  std::memcpy(res, scratch, kScratchSize * sizeof(T));
  return res - arr;
}

template <size_t kScratchSize, typename T>
size_t Partition(T* arr, size_t n, T* scratch) {
  n -= 1;
  auto pivot = arr[n];
  auto res = PartitionImpl<kScratchSize>(pivot, arr, n, scratch);
  arr[n] = arr[res];
  arr[res] = pivot;
  return res;
}

template <size_t kScratchSize, typename T>
void QuickSortImpl(T* arr, size_t n, T* scratch) {
  if (n > kScratchSize) {
    MedianOfThree(arr, n);
    auto p = Partition<kScratchSize>(arr, n, scratch);
    QuickSortImpl<kScratchSize>(arr, p, scratch);
    QuickSortImpl<kScratchSize>(arr + p + 1, n - p - 1, scratch);
  } else {
    QuickSortScratch(arr, n, scratch);
  }
}

template <size_t kScratchSize = 512, typename T>
void QuickSort(T* arr, size_t n) {
  T scratch[kScratchSize];
  QuickSortImpl<kScratchSize>(arr, n, scratch);
}

}  // namespace exp_gerbens

int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	std::vector<int>a(N);
	for(int i=0;i<N;i++)a[i]=i+1;
	int lastx=0;
	for(;Q--;){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		x--;y--;
		if(t==1)std::swap(a[x],a[x+1]);
		if(t==2){
			//std::sort(a.begin()+x,a.begin()+y+1);
			exp_gerbens::QuickSort(&a[x],y+1-x);
		}
	}
	for(auto &e:a)printf("%d ",e);
}
