#pragma once
#ifndef POHAN_PRIORITY_QUEUE_H
#define POHAN_PRIORITY_QUEUE_H

#include <iostream>
#include <vector>

namespace pohan {
	template <typename T>
	class priority_queue {
	private:
		std::vector<T> heap;

	public:
		priority_queue() {}

		~priority_queue() {}

		bool empty() {
			return heap.size() == 0;
		}

		size_t size() {
			return heap.size();
		}

		T top() {
			return *heap.begin();
		}

		void push(T& t) {
			heap.push_back(t);
			if (heap.size() == 1) return;
			int child = heap.size() - 1;
			int parent; // = (child - 1) / 2;
			while (child > 0) {
				int parent = (child - 1) / 2;
				if (heap[child] > heap[parent]) {
					T tmp = heap[child];
					heap[child] = heap[parent];
					heap[parent] = tmp;
				}
				else
					break;
				child = parent;
			}
			return;
		}

		void pop() {
			//swap top element & the last element
			if (heap.size() == 0) return;
			int N = heap.size() - 1;
			swap(heap[0], heap[N]);
			heap.pop_back();
			int parent = 0;
			int leftChild = 1, rightChild = 2;
			while (leftChild < N) {
				//right child not exist
				if (rightChild >= N) {
					if (heap[leftChild] > heap[parent]) {
						swap(heap[leftChild], heap[parent]);
						parent = leftChild;
					}
					else break;
				}
				else {
					if (heap[parent] >= std::max(heap[leftChild], heap[rightChild]))
						break;
					if (heap[leftChild] > heap[rightChild]) {
						swap(heap[parent], heap[leftChild]);
						parent = leftChild;
					}
					else {
						swap(heap[parent], heap[rightChild]);
						parent = rightChild;
					}

				}
						
				leftChild = 2 * parent + 1;
				rightChild = 2 * parent + 2;
				
			}
			//std::cout << (int)heap.end() - 1;
			return;

		}

		void showPQ() {
			for (T data : heap) {
				std::cout << data << ", ";
			}
			std::cout << std::endl;
		}

		void swap(T &a, T &b) {
			T tmp = a;
			a = b;
			b = tmp;
		}
	};
}

#endif 
