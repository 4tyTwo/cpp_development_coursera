#include <vector>
#include <algorithm>

using namespace std;

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
//};

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
            return;
        }
    };
    vector<FunctionPart> operations;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}
