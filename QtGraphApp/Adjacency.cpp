#include "Adjacency.h"



Adjacency::Adjacency(QWidget* parent): QWidget(parent) {
		directed = false;
		valued = false;
		first = nullptr;
		second = nullptr;
		value = 0.0;
	}

Adjacency::Adjacency(bool temp_dir, bool temp_valued,
					 GraphNode* temp_first, GraphNode* temp_second,
					 double temp_value, QWidget* parent) : QWidget(parent) {
	directed = temp_dir;
	valued = temp_valued;
	first = temp_first;
	second = temp_second;
	value = temp_value;
}

Adjacency::~Adjacency() {
	delete first;
	delete second;
}
