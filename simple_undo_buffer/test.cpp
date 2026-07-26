#include <cstddef>
#include <iostream>
#include <deque>
#include <string_view>
#include <array>

enum class CommandType {
	MoveLeft,
	MoveRight,
	MoveForward,
	MoveBackward
};

class RoboCommander {
    private:
        static constexpr std::array<std::string_view, 4> commands = { "MoveLeft", "MoveRight", "MoveForward", "MoveBackward" }; 
        std::deque<CommandType> history;
        std::string_view getCommand(CommandType type) const; 
    public:
        RoboCommander() = default;
        RoboCommander(const RoboCommander& other) = delete;
        RoboCommander& operator=(const RoboCommander& other) = delete;
        void AddCommand(CommandType type);
        void UndoCommand(void);
        void Execute(void) const;
};

std::string_view RoboCommander::getCommand(CommandType type) const {
    return this->commands[static_cast<size_t>(type)];
}

void RoboCommander::AddCommand(CommandType type) {
    this->history.push_back(type);
}

void RoboCommander::UndoCommand(void) {
    if(this->history.empty()) {
        return;
    }
    this->history.pop_back();
}

void RoboCommander::Execute(void) const {
    for(CommandType type : history) {
        std::cout << this->getCommand(type) << "\n";
    }
    std::cout << "Ready\n";
}

int main()
{
	RoboCommander commander;
	commander.AddCommand(CommandType::MoveLeft);
	commander.AddCommand(CommandType::MoveRight);
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(CommandType::MoveLeft);
	commander.AddCommand(CommandType::MoveForward);
	commander.AddCommand(CommandType::MoveLeft);
	commander.AddCommand(CommandType::MoveForward);
	commander.AddCommand(CommandType::MoveRight);
	commander.AddCommand(CommandType::MoveBackward);
	commander.Execute();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.UndoCommand();
	commander.AddCommand(CommandType::MoveForward);
	commander.Execute();
	return 0;
}
