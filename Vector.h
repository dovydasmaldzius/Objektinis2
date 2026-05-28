#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <algorithm>
#include <initializer_list>
#include <memory>
#include <utility>
#include <cstring>
#include <iostream>
/**
 * @class Vector
 * @brief A custom implementation of a dynamic array container, mimicking std::vector
 * @tparam T The type of elements stored in the vector
 * 
 * This is a custom implementation of a dynamic array container that provides
 * similar functionality to std::vector. It manages its own memory allocation
 * and deallocation, and automatically grows when needed.
 */
template<typename T>
class Vector {
public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;

class iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

iterator(pointer ptr = nullptr) : ptr_(ptr) {}

reference operator*() const { return *ptr_; }
pointer operator->() const { return ptr_; }
        
iterator& operator++() { ++ptr_; return *this; }
iterator operator++(int) { iterator tmp = *this; ++ptr_; return tmp; }
iterator& operator--() { --ptr_; return *this; }
iterator operator--(int) { iterator tmp = *this; --ptr_; return tmp; }
        
iterator operator+(difference_type n) const { return iterator(ptr_ + n); }
iterator operator-(difference_type n) const { return iterator(ptr_ - n); }
difference_type operator-(const iterator& other) const { return ptr_ - other.ptr_; }
        
iterator& operator+=(difference_type n) { ptr_ += n; return *this; }
iterator& operator-=(difference_type n) { ptr_ -= n; return *this; }
        
reference operator[](difference_type n) const { return ptr_[n]; }
        
bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
bool operator!=(const iterator& other) const { return ptr_ != other.ptr_; }
bool operator<(const iterator& other) const { return ptr_ < other.ptr_; }
bool operator<=(const iterator& other) const { return ptr_ <= other.ptr_; }
bool operator>(const iterator& other) const { return ptr_ > other.ptr_; }
bool operator>=(const iterator& other) const { return ptr_ >= other.ptr_; }

private:
pointer ptr_;
friend class Vector;
};

class const_iterator {
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;

const_iterator(pointer ptr = nullptr) : ptr_(ptr) {}
const_iterator(const iterator& it) : ptr_(it.ptr_) {}

    reference operator*() const { return *ptr_; }
    pointer operator->() const { return ptr_; }
        
const_iterator& operator++() { ++ptr_; return *this; }
const_iterator operator++(int) { const_iterator tmp = *this; ++ptr_; return tmp; }
const_iterator& operator--() { --ptr_; return *this; }
const_iterator operator--(int) { const_iterator tmp = *this; --ptr_; return tmp; }
const_iterator operator+(difference_type n) const { return const_iterator(ptr_ + n); }
const_iterator operator-(difference_type n) const { return const_iterator(ptr_ - n); }
difference_type operator-(const const_iterator& other) const { return ptr_ - other.ptr_; } 
const_iterator& operator+=(difference_type n) { ptr_ += n; return *this; }
const_iterator& operator-=(difference_type n) { ptr_ -= n; return *this; }
        
    reference operator[](difference_type n) const { return ptr_[n]; }
        
bool operator==(const const_iterator& other) const { return ptr_ == other.ptr_; }
bool operator!=(const const_iterator& other) const { return ptr_ != other.ptr_; }
bool operator<(const const_iterator& other) const { return ptr_ < other.ptr_; }
bool operator<=(const const_iterator& other) const { return ptr_ <= other.ptr_; }
bool operator>(const const_iterator& other) const { return ptr_ > other.ptr_; }
bool operator>=(const const_iterator& other) const { return ptr_ >= other.ptr_; }

private:
pointer ptr_;
friend class Vector;
};

using reverse_iterator = std::reverse_iterator<iterator>;
using const_reverse_iterator = std::reverse_iterator<const_iterator>;

Vector() noexcept : data_(nullptr), size_(0), capacity_(0) {}

explicit Vector(size_type n) : data_(nullptr), size_(0), capacity_(0) {
if (n > 0) {
    data_ = allocate_memory(n);
    capacity_ = n;
    size_ = n;
for (size_type i = 0; i < n; ++i) {
    new (&data_[i]) T();
}
}
}

Vector(size_type n, const T& value) : data_(nullptr), size_(0), capacity_(0) {
if (n > 0) {
    data_ = allocate_memory(n);
    capacity_ = n;
    size_ = n;
for (size_type i = 0; i < n; ++i) {
    new (&data_[i]) T(value);
}
}
}

template<class InputIt>
Vector(InputIt first, InputIt last, 
    typename std::enable_if<!std::is_integral<InputIt>::value>::type* = nullptr) : data_(nullptr), size_(0), capacity_(0) {
for (auto it = first; it != last; ++it) {
    push_back(*it);
}
}

Vector(std::initializer_list<T> il) : data_(nullptr), size_(0), capacity_(0) {
for (const auto& value : il) {
    push_back(value);
}
}

// Copy constructor
Vector(const Vector& other) : data_(nullptr), size_(0), capacity_(0) {
if (other.size_ > 0) {
    data_ = allocate_memory(other.size_);
    capacity_ = other.size_;
    size_ = other.size_;
for (size_type i = 0; i < size_; ++i) {
    new (&data_[i]) T(other.data_[i]);
}
}
}

// Move constructor
Vector(Vector&& other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

// Destructor
~Vector() {
    clear();
    deallocate_memory(data_);
}

// Copy assignment
Vector& operator=(const Vector& other) {
if (this != &other) {
    clear();
    deallocate_memory(data_);
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;

if (other.size_ > 0) {
    data_ = allocate_memory(other.size_);
    capacity_ = other.size_;
    size_ = other.size_;
for (size_type i = 0; i < size_; ++i) {
    new (&data_[i]) T(other.data_[i]);
}
}
}
return *this;
}

// Move assignment
Vector& operator=(Vector&& other) noexcept {
if (this != &other) {
    clear();
    deallocate_memory(data_);
    data_ = other.data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}
return *this;
}

// Initializer list assignment
Vector& operator=(std::initializer_list<T> il) {
    clear();
for (const auto& value : il) {
    push_back(value);
}
return *this;
}

    iterator begin() noexcept { return iterator(data_); }
    const_iterator begin() const noexcept { return const_iterator(data_); }
    const_iterator cbegin() const noexcept { return const_iterator(data_); }

    iterator end() noexcept { return iterator(data_ + size_); }
    const_iterator end() const noexcept { return const_iterator(data_ + size_); }
    const_iterator cend() const noexcept { return const_iterator(data_ + size_); }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(end()); }

    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }
    const_reverse_iterator crend() const noexcept { return const_reverse_iterator(begin()); }

    size_type size() const noexcept { return size_; }
    size_type capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return size_ == 0; }

void reserve(size_type n) {
if (n > capacity_) {
    reallocate(n);
}
}

void shrink_to_fit() {
if (capacity_ > size_) {
    if (size_ == 0) {
    deallocate_memory(data_);
    data_ = nullptr;
    capacity_ = 0;
} 
else {
    T* new_data = allocate_memory(size_);
for (size_type i = 0; i < size_; ++i) {
    new (&new_data[i]) T(std::move(data_[i]));
    data_[i].~T();
}
    deallocate_memory(data_);
    data_ = new_data;
    capacity_ = size_;
}
}
}

    reference operator[](size_type idx) {
return data_[idx];
}

    const_reference operator[](size_type idx) const {
return data_[idx];
}

    reference at(size_type idx) {
if (idx >= size_) {
    throw std::out_of_range("Vector index out of range");
}
return data_[idx];
}

    const_reference at(size_type idx) const {
if (idx >= size_) {
    throw std::out_of_range("Vector index out of range");
}
return data_[idx];
}

    reference front() {
return data_[0];
}

    const_reference front() const {
return data_[0];
}

    reference back() {
return data_[size_ - 1];
}

    const_reference back() const {
return data_[size_ - 1];
}

    pointer data() noexcept { return data_; }
    const_pointer data() const noexcept { return data_; }

    void clear() noexcept {
for (size_type i = 0; i < size_; ++i) {
    data_[i].~T();
}
size_ = 0;
}

    void push_back(const T& value) {
if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
}
    new (&data_[size_]) T(value);
    ++size_;
}

    void push_back(T&& value) {
if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
}
    new (&data_[size_]) T(std::move(value));
    ++size_;
}

    template<class... Args>
    reference emplace_back(Args&&... args) {
if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
}
    new (&data_[size_]) T(std::forward<Args>(args)...);
return data_[size_++];
}

    void pop_back() {
if (size_ > 0) {
    data_[--size_].~T();
}
}

    iterator insert(const_iterator pos, const T& value) {
    difference_type offset = pos - cbegin();
if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
}
    iterator it = begin() + offset;
for (iterator it_last = end() - 1; it_last >= it; --it_last) {
    new (&it_last[1]) T(std::move(*it_last));
    it_last->~T();
}
    new (it.ptr_) T(value);
    ++size_;
return it;
}

    iterator insert(const_iterator pos, T&& value) {
    difference_type offset = pos - cbegin();
if (size_ == capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
}
    iterator it = begin() + offset;
for (iterator it_last = end() - 1; it_last >= it; --it_last) {
    new (&it_last[1]) T(std::move(*it_last));
    it_last->~T();
}
    new (it.ptr_) T(std::move(value));
    ++size_;
    return it;
}

    iterator insert(const_iterator pos, size_type count, const T& value) {
if (count == 0) return iterator(const_cast<pointer>(pos.ptr_));
    difference_type offset = pos - cbegin();
if (size_ + count > capacity_) {
    reserve(std::max(size_ + count, capacity_ * 2));
}
    iterator it = begin() + offset;
for (iterator it_last = end() - 1; it_last >= it; --it_last) {
    new (&it_last[count]) T(std::move(*it_last));
    it_last->~T();
}
for (size_type i = 0; i < count; ++i) {
    new (&it.ptr_[i]) T(value);
}
    size_ += count;
return it;
}

    template<class InputIt>
iterator insert(const_iterator pos, InputIt first, InputIt last,
    typename std::enable_if<!std::is_integral<InputIt>::value>::type* = nullptr) {
difference_type offset = pos - cbegin();
    size_type count = std::distance(first, last);
if (count == 0) return iterator(const_cast<pointer>(pos.ptr_));
    if (size_ + count > capacity_) {
    reserve(std::max(size_ + count, capacity_ * 2));
}
    iterator it = begin() + offset;
for (iterator it_last = end() - 1; it_last >= it; --it_last) {
    new (&it_last[count]) T(std::move(*it_last));
    it_last->~T();
}
for (size_type i = 0; i < count; ++i, ++first) {
    new (&it.ptr_[i]) T(*first);
}
    size_ += count;
return it;
}

    iterator insert(const_iterator pos, std::initializer_list<T> il) {
return insert(pos, il.begin(), il.end());
}

    iterator erase(const_iterator pos) {
    difference_type offset = pos - cbegin();
    iterator it = begin() + offset;
    it->~T();
for (iterator next = it + 1; next != end(); ++it, ++next) {
    new (it.ptr_) T(std::move(*next));
}
    --size_;
return iterator(const_cast<pointer>(pos.ptr_));
}

    iterator erase(const_iterator first, const_iterator last) {
if (first == last) return iterator(const_cast<pointer>(first.ptr_));
        
    difference_type offset = first - cbegin();
    difference_type count = last - first;
for (const_iterator it = first; it != last; ++it) {
    it.ptr_->~T();
}
    iterator dst = begin() + offset;
    iterator src = begin() + offset + count;
while (src != end()) {
    new (dst.ptr_) T(std::move(*src));
    src->~T();
    ++dst;
    ++src;
}
        
    size_ -= count;
return iterator(const_cast<pointer>(first.ptr_));
}

    void resize(size_type n) {
if (n > size_) {
    reserve(n);
for (size_type i = 0; i < n - size_; ++i) {
    new (&data_[size_ + i]) T();
}
}
else if (n < size_) {
    for (size_type i = n; i < size_; ++i) {
    data_[i].~T();
}
}
    size_ = n;
}

    void resize(size_type n, const T& value) {
if (n > size_) {
    reserve(n);
for (size_type i = 0; i < n - size_; ++i) {
    new (&data_[size_ + i]) T(value);
}
} 
else if (n < size_) {
    for (size_type i = n; i < size_; ++i) {
    data_[i].~T();
}
}
    size_ = n;
}

    void assign(size_type n, const T& value) {
    clear();
if (capacity_ < n) {
    deallocate_memory(data_);
    data_ = allocate_memory(n);
    capacity_ = n;
}
for (size_type i = 0; i < n; ++i) {
    new (&data_[i]) T(value);
}
    size_ = n;
}

    template<class InputIt>
    void assign(InputIt first, InputIt last,
    typename std::enable_if<!std::is_integral<InputIt>::value>::type* = nullptr) {
    clear();
for (auto it = first; it != last; ++it) {
    push_back(*it);
}
}

    void swap(Vector& other) noexcept {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

    bool operator==(const Vector& other) const {
if (size_ != other.size_) return false;
    for (size_type i = 0; i < size_; ++i) {
if (data_[i] != other.data_[i]) return false;
}
return true;
}

    bool operator!=(const Vector& other) const {
return !(*this == other);
}

    bool operator<(const Vector& other) const {
return std::lexicographical_compare(begin(), end(), other.begin(), other.end());
}

    bool operator<=(const Vector& other) const {
return !(other < *this);
}

    bool operator>(const Vector& other) const {
return other < *this;
}

    bool operator>=(const Vector& other) const {
return !(*this < other);
}

size_type get_reallocation_count() const { return reallocation_count_; }

private:
static T* allocate_memory(size_type n) {
    if (n == 0) return nullptr;
return static_cast<T*>(::operator new[](n * sizeof(T)));
}

    static void deallocate_memory(T* ptr) {
    ::operator delete[](ptr);
}

    pointer data_;
    size_type size_;
    size_type capacity_;
    size_type reallocation_count_ = 0;

    void reallocate(size_type new_capacity) {
if (new_capacity <= capacity_) return;
    T* new_data = allocate_memory(new_capacity);
for (size_type i = 0; i < size_; ++i) {
    new (&new_data[i]) T(std::move(data_[i]));
    data_[i].~T();
}
        
deallocate_memory(data_);
data_ = new_data;
capacity_ = new_capacity;
++reallocation_count_;
}
};

#endif // VECTOR_H
