#include <vector>
#include <algorithm>

using namespace std;

class Function {
    public:
    void AddPart(const char& operation, const double& val)
    {
        operations.push_back({operation, val});
    }

    double Apply(double value) const
    {
        double res = value;
        for (const auto& item : operations) {
            res = item.Apply(res);
        }
        return res; 
    }

    void Invert()
    {
        reverse(operations.begin(), operations.end());
        for (auto& item : operations)
            item.Invert();
    }

    private:
    struct FunctionPart {
        char operation;
        double value;
        FunctionPart(char op, double v)
        {
            operation = op;
            value = v;
        }
        double Apply(double initial) const
        {
            if (operation == '+')
                return initial + value;
            if (operation == '-')
                return initial - value;
            if (operation == '*')
                return initial * value;
            if (operation == '/')
                return initial / value;    
            return initial;
        }
        void Invert()
        {
            if (operation == '+') {
                operation = '-';
                return;
            }
            if (operation == '-') {
                operation = '+';
                return;
            }
            if (operation == '*') {
                operation = '/';
                return;
            }
            if (operation == '/') {
                operation = '*';
                return;
            }
            return;
        }
    };
    vector<FunctionPart> operations;
};
