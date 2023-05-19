#include <model/bulkmodel.h>

#include <loggers/consolelogger.h>
#include <loggers/filelogger.h>

#include <handler/commandsfactory.h>
#include <handler/handler.h>

int main(int argc, char *argv[])

{
    if (argc != 2)
    {
        std::cout << "Usage: bulk N \n where N is size of block";
        return 1;
    }

    int commandsNumber = atoll(argv[1]);

    if (commandsNumber <= 0)
    {
        std::cout << "Commands number must be positive";
        return 1;
    }

    BulkModel bModel(commandsNumber);

    std::shared_ptr<IObserver> fileLogger    = std::make_shared<FileLogger>();
    std::shared_ptr<IObserver> consoleLogger = std::make_shared<ConsoleLogger>();

    bModel.subscribe(fileLogger);
    bModel.subscribe(consoleLogger);

    std::unique_ptr<CommandsFactory> cmdFactory = std::make_unique<CommandsFactory>();

    cmdFactory->addCommand(COMMAND::BEGIN, std::make_unique<BeginBlockCommand>(&bModel));
    cmdFactory->addCommand(COMMAND::END, std::make_unique<EndBlockCommand>(&bModel));
    cmdFactory->addCommand(COMMAND::ADD, std::make_unique<StoreDataCommand>(&bModel));
    cmdFactory->addCommand(COMMAND::EF, std::make_unique<EofCommand>(&bModel));

    Handler handler(std::move(cmdFactory), std::cin);

    handler.loop();

    return 0;
}
