#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string &val) {
    if (tail_ == nullptr) {
        tail_ = new Item();
        head_ = tail_;
    }

    if (tail_->last < ARRSIZE) {
        tail_->val[tail_->last] = val;
        tail_->last++;
    } else {
        Item* temp = new Item();
        temp->val[0] = val;
        temp->last = 1;
        temp->first = 0;
        temp->prev = tail_;
        tail_->next = temp;
        tail_ = temp;
    }
    size_++;
}
void ULListStr::pop_back() {
	if (tail_ == nullptr) {return;}

	tail_->last--;

	if (tail_->last == tail_->first) {
		Item* temp = tail_;
		tail_ = tail_->prev;

		if (tail_ != nullptr) {
			tail_->next = nullptr;
		} else {
			head_ = nullptr;
		}

		delete temp;
	}
	size_--;
}
void ULListStr::push_front(const std::string &val) {
	if (head_ == nullptr) {
		head_ = new Item();
		head_->last = ARRSIZE;
		head_->first = ARRSIZE;
		tail_ = head_;
	}
	if (head_->first > 0) {
        head_->val[head_->first-1] = val;
        head_->first--;
    } else {
        Item* temp = new Item();
		temp->last = ARRSIZE;
		temp->first = ARRSIZE-1;
        temp->val[ARRSIZE-1] = val;
        temp->next = head_;
        head_->prev = temp;
        head_ = temp;
    }
	size_++;
}
void ULListStr::pop_front() {
	if (head_ == nullptr) {return;}

	head_->first++;

	if (head_->first == head_->last) {
		Item* temp = head_;
		head_ = head_->next;

		if (head_ != nullptr) {
			head_->prev = nullptr;
		} else {
			tail_ = nullptr;
		}

		delete temp;
	}
	size_--;
}
std::string const & ULListStr::back() const {
	if (tail_ == nullptr) {
        throw std::out_of_range("List is empty");
    }
	return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const {
	if (head_ == nullptr) {
        throw std::out_of_range("List is empty");
    }
	return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
	Item* curr = head_;
	int index = 0;

	while (curr != nullptr) {
		int itemSize = curr->last - curr->first;

		if (loc < index + itemSize) {
			return &curr->val[curr->first + (loc - index)];
		}

		index += itemSize;
		curr = curr->next;
	}

	return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
