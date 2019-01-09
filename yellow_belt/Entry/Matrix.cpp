#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

using namespace std;

class Matrix {
public:
	Matrix()
	{
		row_num = col_num = 0;
	}
	Matrix(int num_rows, int num_cols)
	{
		try
		{
			Reset(num_rows, num_cols);
		}
		catch (...)
		{
			throw;
		}
	}

	void Reset(int num_rows, int num_cols)
	{
		if (num_rows < 0 || num_cols < 0)
			throw out_of_range("Number of rows or collumns can't be negative");
		matrix.resize(num_rows);
		for (auto& item : matrix)
			item.resize(num_cols);
        nullify_elements();
		row_num = num_rows;
		col_num = num_cols;
	}

	int At(int row, int col) const
	{
		try
		{
			return matrix.at(row).at(col);
		}
		catch (...)
		{
			throw;
		}
	}

	int& At(int row, int col)
	{
		try
		{
			return matrix.at(row).at(col);
		}
		catch (...)
		{
			throw;
		}
	}

	int GetNumRows() const
	{
		return row_num;
	}

	int GetNumColumns() const
	{
		return col_num;
	}

	bool operator== (const Matrix& other) const
	{
		if (check_sizes_equality(other))
		{
			for (int i = 0; i < GetNumRows(); ++i)
				for (int j = 0; j < GetNumColumns(); ++j)
					if (At(i, j) != other.At(i, j))
						return false;
		}
		else
		{
			return false;
		}
		return true;
	}

	Matrix operator+ (const Matrix& other) const
	{
		if (check_sizes_equality(other))
		{
			Matrix res(GetNumRows(), GetNumColumns());
			for (int i = 0; i < GetNumRows(); ++i)
				for (int j = 0; j < GetNumColumns(); ++j)
					res.At(i, j) = At(i, j) + other.At(i, j);
			return res;
		}
		else
		{
			throw invalid_argument("Matrixes have different dimensions, sizes are: " + to_string(row_num) + " " + to_string(col_num) + " " + to_string(other.row_num) + " " + to_string(other.col_num));
		}
	}

private:
    void nullify_elements()
    {
        for (auto& i : matrix)
            for (int& j : i)
                j = 0;
    }

	bool check_sizes_equality(const Matrix& other) const
	{
		return (row_num == other.row_num && col_num == other.col_num);
	}

	vector<vector<int>> matrix;
	int row_num, col_num;
};

istream& operator>> (istream& in, Matrix& matrix)
{
	int num_rows, num_cols;
	in >> num_rows >> num_cols;
	matrix.Reset(num_rows, num_cols);
	for (int i = 0; i < num_rows; ++i)
		for (int j = 0; j < num_cols; ++j)
			in >> matrix.At(i, j);
	return in;
}

ostream& operator<< (ostream& out, const Matrix matrix)
{
	out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
	for (int i = 0; i < matrix.GetNumRows(); ++i) {
		for (int j = 0; j < matrix.GetNumColumns(); ++j)
			out << matrix.At(i, j) << " ";
		out << endl;
	}
	return out;
}
