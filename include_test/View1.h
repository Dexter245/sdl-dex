#ifndef VIEW1_H_
#define VIEW1_H_

#include "View.h"
#include "Model1.h"

class View1 : public dex::View {
private:
    Model1 *model;

public:
    explicit View1(Model1 *model);
    ~View1(){}

    void render() override;
};

#endif