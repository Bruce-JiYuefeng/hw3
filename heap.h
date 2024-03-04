#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  std::vector<T> data; 
    PComparator comp; 
    int m_ary; 
    
    void heapifyUp(size_t idx);
    void heapifyDown(size_t idx);
};


template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_ary(m), comp(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}


template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return data.empty();
}


template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return data.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    data.push_back(item);
    heapifyUp(data.size() - 1);
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  std::swap(data[0], data.back());
  data.pop_back();
  if (!empty()) {
    heapifyDown(0);
  }


}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t idx) {
    while (idx > 0) {
        size_t parent = (idx - 1) / m_ary;
        if (comp(data[idx], data[parent])) {
            std::swap(data[idx], data[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t idx) {
    size_t child;
    while ((child = m_ary * idx + 1) < data.size()) {
        size_t minMax = idx;
        for (int i = 0; i < m_ary && i + child < data.size(); ++i) {
            if (comp(data[child + i], data[minMax])) {
                minMax = child + i;
            }
        }
        if (minMax != idx) {
            std::swap(data[idx], data[minMax]);
            idx = minMax;
        } else {
            break;
        }
    }
}

#endif

