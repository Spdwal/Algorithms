#prama once
#include<vector>
#include<iostream>
#include<iterator>
#include<cassert>
#include<initializer_list>
using namespace std;

class Matrix{
public:
    Matrix() = default;
    Matrix(const Matrix&) = default;
    Matrix(Matrix &&) = default;
    Matrix(int m, int n):ivec(m, vector<int>(n)){};
	Matrix(const vector<int> &vec):ivec{{vec}} {}
	Matrix operator=(Matrix &&m){ std::swap(m.ivec, ivec);}
    Matrix(initializer_list<initializer_list<int>> && init)
    {
        for(auto sub: init)
        {
            ivec.push_back(static_cast<vector<int>>(sub));
        }
    }

    friend ostream& operator<<(ostream& out, const Matrix &m)
    {
        for(auto sub: m.ivec)
        {
            copy(sub.begin(), sub.end(), ostream_iterator<int>(out, " "));
            out << endl;
        }
        return out;
    }

    int rows() const{ return ivec.size();}
    int cols() const {return ivec[0].size();}
    vector<int>& operator[](int num){ return ivec[num];}
	const vector<int>& operator[](int num) const{return ivec[num];}

    void transpose()
    {
        vector<vector<int>> tmp(cols(), vector<int>(rows()));
        for(int i = 0; i < rows(); ++i)
        {
            for(int j = 0; j < cols(); ++j)
            {
                tmp[j][i] = ivec[i][j];
            }
        }
        std::swap(ivec, tmp);
    }

	friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
	//friend Matrix operator*(const Matrix& lhs, const vector<int>& rhs);

private:
    vector<vector<int>> ivec;
};


Matrix operator*(const Matrix& lhs, const Matrix& rhs)
{
	assert(lhs.rows() == rhs.cols());
	Matrix result(lhs.rows(), rhs.cols());
	for(int i = 0; i < lhs.rows(); ++i)
	{
		for(int j = 0; j < rhs.cols(); ++j)
		{
			for(int k = 0; k < lhs.cols(); ++k)
			{
				result[i][j] += lhs[i][k] * rhs[k][j];
			}
		}
	}

	return result;
}


// Matrix operator*(const Matrix& lhs, const vector<int>& rhs)
// {
// 	return lhs * Matrix(rhs);
// }
