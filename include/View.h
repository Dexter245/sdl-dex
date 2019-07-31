#ifndef VIEW_H_
#define VIEW_H_

namespace dex{

    class View{
    private:

    public:
        virtual void render() = 0;
        virtual ~View() = 0;
    };

    inline View::~View() {}

}

#endif