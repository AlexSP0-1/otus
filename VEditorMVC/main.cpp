#include <memory>

#include "controller.h"
#include "model.h"
#include "painter.h"
#include "view.h"

int main(int, char **)
{
    std::unique_ptr<IModel> model           = std::make_unique<Model>();
    std::unique_ptr<IPainter> painter       = std::make_unique<Painter>();
    std::unique_ptr<IObserver> view         = std::make_unique<View>(model.get(), painter.get());
    std::unique_ptr<IController> controller = std::make_unique<Controller>(model.get(), view.get());

    model->subscribe(view.get());

    controller->loop();

    return 0;
}
