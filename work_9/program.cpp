#include "program.h"

void X::setState(StateContainer& state) {
    *this->x1 = *state.state["x1"];
    *this->x2 = *state.state["x2"];
}

StateContainer X::getState() {
    StateContainer container;
    container.state["x1"] = std::make_unique<int32_t>(*x1);
    container.state["x2"] = std::make_unique<int32_t>(*x2);
    return container;
}

X::~X() {
    delete x1;
    delete x2;
}

X::X(int32_t x1, int32_t x2) : x1(new int32_t(x1)), x2(new int32_t(x2)) {
}

Y::Y(int32_t x1, int32_t x2, int32_t y) : X(x1, x2), y(new int(y)) {
}

Y::~Y() {
    delete y;
}

void Y::setState(StateContainer& state) {
    X::setState(state);
    *this->y = *state.state["y"];
}

StateContainer Y::getState() {
    StateContainer container = X::getState();
    container.state["y"] = std::make_unique<int32_t>(*y);
    return container;
}

int32_t Y::Run() {
    return (*x1 - *x2) / *y;
}
