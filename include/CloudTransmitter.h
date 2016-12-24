//
// Created by Célian Garcia on 26/11/2016.
//

#ifndef FIREFLY_CLOUD_TRANSMITTER_H
#define FIREFLY_CLOUD_TRANSMITTER_H

#include <vector>
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

enum Operation {
    ADD,
    REMOVE
};
struct Element {
    int id;
    float x;
    float y;
    float z;
    Operation op;
};

class CloudTransmitter: public vector<Vec3f> {
public:
    virtual void push_back(const Vec3f& __x);
private:
    vector<Element> elements = {};
    void appendElement(float x, float y, float z, Operation op);
};

#endif //FIREFLY_CLOUD_TRANSMITTER_H
