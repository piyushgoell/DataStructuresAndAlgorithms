#include <iostream>
#include <stack>
#include <string>

struct Bracket
{
    Bracket(char type, int position) : type(type), position(position) {}

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);
    size_t faulty_index = -1;
    std::stack<Bracket> opening_brackets_stack;
    for (size_t position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            opening_brackets_stack.push(Bracket(next, position + 1));
        }

        if (next == ')' || next == ']' || next == '}')
        {
            if (opening_brackets_stack.size() == 0)
            {
                faulty_index = position + 1;
                break;
            }

            else if (opening_brackets_stack.top().Matchc(next))
                opening_brackets_stack.pop();
            else
            {
                faulty_index = position + 1;
                break;
            }
        }
    }

    if (opening_brackets_stack.size() == 0 && faulty_index == -1)
        std::cout << "Success\n";
    else if (opening_brackets_stack.size() != 0 && faulty_index == -1)
        std::cout << opening_brackets_stack.top().position << "\n";
    else
        std::cout << faulty_index << "\n";
    return 0;
}
