#pragma once

#include <string>
#include <memory>
#include <stdint.h>
#include <map>
#include <string>

struct StateContainer {
    std::map<std::string, std::unique_ptr<int32_t>> state;
};

class X {
protected:
    int32_t* x1;
    int32_t* x2;

public:
    virtual void setState(StateContainer& state);
    virtual StateContainer getState();

public:
    X(int32_t x1, int32_t x2);

public:
    virtual ~X();
};

class Y : public X {
protected:
    int32_t* y;

public:
    Y(int32_t x1, int32_t x2, int32_t y);

public:
    virtual ~Y();

public:
    virtual void setState(StateContainer& state) override;

    virtual StateContainer getState() override;

public:
    int32_t Run();
};