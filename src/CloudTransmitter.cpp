//
// Created by Célian Garcia on 26/11/2016.
//

#include "CloudTransmitter.h"

void CloudTransmitter::push_back(const Vec3f &__x) {
    vector<Vec3f>::push_back(__x);
    this->appendElement(__x[0], __x[1], __x[2], Operation::ADD);
}

void CloudTransmitter::appendElement(float x, float y, float z, Operation op) {
    Element element;
    element.id = this->elements.size();
    element.x = x;
    element.y = y;
    element.z = z;
    element.op = op;
    this->elements.push_back(element);
}