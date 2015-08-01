#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    For example,

    Consider the following matrix:

    [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    Given target = 3, return true.

    Hide Tags Array Binary Search
    Show Similar Problems


    74Search a 2DMatrix.cpp
*/
/**
    Solution:
    row1 with row2
    we first search midline= (row1+row2)/2 using the classic search method binary search,if find then return true
    otherwise ,we must judge the target value with the midline's last value and first value,that is compare with the
    nums[midline][0] and nums[midline][last column]
    if target is larger than nums[midline][last column] then we can search from midline+1 to row2
    if target is less than nums[midline][0] then we can search from row1 to midline - 1
    this is the binary search applied in 2D array,that is matrix.

    Complexity:
        the row will be O(log(m)),m is the total row of matrix
        the specified row that the binary search is applied is O(log(n)),where n is the total columns of matrix
        so the complexity will be O(log(m)*log(n)) which is better for the row by row search using binary search method,which
        complexity will be O(m*log(n))
*/


void printMatrix(vector<vector<int> > res){
     int size = res.size();
     for(int i=0;i<size;++i)
        cout<<"==";
     cout<<endl;
     for(auto& line:res){
            copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
            cout<<endl;
        }

}

class Solution {

       public:

            bool searchMatrix(vector<vector<int>>& matrix, int target) {
                 int begin = 0;
                 int size = matrix.size();
                 int end = size - 1;
                 return searchLine(matrix,target,begin,end);

            }


            bool searchLine(vector<vector<int> >&nums,int target,int bline,int eline){
                 int row = nums.size();
                 if(row == 0)
                    return 0;
                 if(bline < 0 || eline < 0)
                    return 0;
                 if(bline > eline)
                    return 0;

                 int col = nums[0].size();
                 if(col == 0)
                    return 0;
                 int midline = (bline + eline)>>1;

                 int lineres = binary_search(nums[midline],target);//search a line
                 if(bline == eline){
                    return lineres;
                 }

                 if(lineres){
                    return 1;
                 }

                 if(target > nums[midline][col-1])//larger than last one{
                {

                    return searchLine(nums,target,midline+1,eline);
                 }
                 else
                    {
                        return  searchLine(nums,target,bline,midline-1);
                    }

                return 0;


            }

            bool binary_search(vector<int>&nums,int target){
//                cout<<"->"<<target<<endl;
                int begin = 0;
                int end = nums.size()-1;
                if(nums.empty())
                    return 0;
                if(begin == end)
                    return target == nums[end];

                while(begin <= end){
                    int mid = (begin+end)>>1;
                    if(target == nums[mid])
                        return 1;
                    else if(target > nums[mid])
                        begin = mid + 1;
                    else
                        end = mid - 1;
                }

                return 0;
            }






};


int main(){
        Solution s;
        vector<vector<int> > array={
//                     {1,   4,  7, 11, 15},
//                      {2,   5,  8, 12, 19},
//                      {3,   6,  9, 16, 22},
//                      {10, 13, 14, 17, 24},
//                      {18, 21, 23, 26, 30}

                      {1,   3,  5,  7},
                      {10, 11, 16, 20},
                      {23, 30, 33, 50}
/*
{ -10 , -9 , -9 , -9 , -9 , -7 , -7 , -6 } ,
{ -4 , -2 , -1 , 0 , 0 , 0, 2 , 3 } ,
{ 4 , 4 , 5 , 7 , 7 , 8 , 8 , 10 } ,
{ 12 , 12 , 12 , 14 , 14 , 15 , 15 , 16 } ,
{ 17 , 18 , 20 , 22 , 22 , 22 , 23 , 24 } ,
{ 27 , 29 , 30 , 32 , 33 , 33 , 34 , 35 } ,
{ 36 , 36 , 37 , 37 , 38 , 39 , 39 , 41 } ,
{ 43 , 44 , 44 , 46 , 46 , 47 , 48 , 48 } ,
{ 51 , 51 , 53 , 53 , 54 , 54 , 55 , 56 } ,
{ 58 , 58 , 59 , 61 , 61 , 63 , 63 , 64 } ,
{ 65 , 67 , 69 , 71 , 72 , 72 , 72 , 74 } ,
{ 77 , 77 , 79 , 81 , 82 , 82 , 84 , 85 } ,
{ 88 , 88 , 89 , 90 , 90 , 90 , 92 , 94 } ,
{ 96 , 97 , 98 , 100 , 101 , 103 , 104 , 106 } ,
{ 108 , 108 , 110 , 111 , 112 , 114 , 115 , 115 } ,
{ 116 , 117 , 117 , 119 , 121 , 121 , 121 , 123 } ,
{ 124 , 125 , 125 , 126 , 127 , 127 , 128 , 130 } ,
{ 132 , 132 , 134 , 134 , 136 , 137 , 137 , 139 } ,
{ 142 , 142 , 142 , 143 , 143 , 144 , 146 , 146 } ,
{ 147 , 147 , 149 , 150 , 151 , 151 , 151 , 153 } ,
{ 155 , 156 , 157 , 159 , 160 , 160 , 160 , 160 } ,
{ 162 , 162 , 164 , 165 , 166 , 166 , 166 , 167 } ,
{ 168 , 169 , 169 , 170 , 171 , 172 , 174 , 176 } ,
{ 178 , 180 , 180 , 180 , 182 , 183 , 183 , 183 } ,
{ 186 , 187 , 187 , 188 , 190 , 190 , 192 , 192 } ,
{ 193 , 194 , 195 , 197 , 198 , 198 , 200 , 202 } ,
{ 205 , 207 , 207 , 207 , 207 , 207 , 207 , 209 } ,
{ 212 , 212 , 212 , 213 , 215 , 215 , 216 , 217 } ,
{ 220 , 222 , 222 , 224 , 224 , 224 , 226 , 228 } ,
{ 230 , 231 , 233 , 234 , 235 , 236 , 236 , 237 } ,
{ 240 , 242 , 244 , 244 , 246 , 246 , 247 , 249 } ,
{ 252 , 253 , 254 , 255 , 257 , 258 , 258 , 260 } ,
{ 262 , 262 , 263 , 264 , 265 , 266 , 266 , 266 } ,
{ 269 , 270 , 272 , 274 , 276 , 276 , 277 , 279 } ,
{ 282 , 282 , 283 , 283 , 285 , 287 , 287 , 288 } ,
{ 290 , 291 , 293 , 294 , 296 , 296 , 296 , 297 } ,
{ 299 , 301 , 301 , 301 , 302 , 303 , 304 , 305 } ,
{ 308 , 308 , 309 , 309 , 310 , 312 , 312 , 313 } ,
{ 314 , 315 , 316 , 318 , 318 , 320 , 321 , 321 } ,
{ 323 , 324 , 325 , 326 , 327 , 329 , 330 , 330 } ,
{ 333 , 334 , 335 , 336 , 336 , 338 , 338 , 339 } ,
{ 341 , 343 , 344 , 346 , 348 , 350 , 351 , 353 } ,
{ 355 , 355 , 355 , 357 , 357 , 358 , 360 , 362 } ,
{ 363 , 364 , 366 , 368 , 369 , 369 , 369 , 370 } ,
{ 372 , 374 , 376 , 378 , 380 , 380 , 380 , 381 } ,
{ 384 , 385 , 386 , 387 , 389 , 391 , 393 , 394 } ,
{ 395 , 395 , 395 , 396 , 398 , 399 , 399 , 399 } ,
{ 400 , 402 , 402 , 403 , 405 , 405 , 407 , 408 } ,
{ 409 , 409 , 410 , 410 , 410 , 411 , 412 , 412 }
*/
        };

        int v = 20;
        bool res = s.searchMatrix(array,v);
        cout<<res<<endl;


}
