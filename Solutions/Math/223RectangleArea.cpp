#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;


/**
    doc
    Find the total area covered by two rectilinear rectangles in a 2D plane.

    Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.


    223Rectangle Area.cpp
*/
/**
    Solutions:    /|\ Y
                   |
         ._________|__________(C,D)
         |         |          |
         |         |__________|____. (G,H)
         |      e1 |          |    |
       --'---------'----------'----|----------->
    (A,B)    (0,0) |    e2         |            X
                   |_______________|
                   (E,F)
    commom area edge:
        e2 = min(C,G) - max(A,E)
        e1 = min(D,H) - max(B,F)
        common area = e1 * e2 if e1 and e2 are valid.


*/
class Solution {

       public:
            int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

                    int hhight = min(D,H);
                    int hlow = max(B,F);
                    int wfront = min(C,G);
                    int wlater = max(A,E);
                    int height = hhight - hlow;
                    int width = wfront - wlater;

                    int edge1height =  D - B;
                    int edge1width  =  C - A;

                    int edge2height =  H - F;
                    int edge2width  =  G - E;

                    int area1 = edge1height*edge1width;

                    if(edge1height<=0 || edge1width<=0)
                        area1 = 0;
                    int area2 = edge2height*edge2width;

                    if(edge2height<=0 || edge2width<=0)
                        area2 = 0;
                    int commonArea = height* width;
                    if(height <=0 ||  width <= 0 || wfront <= wlater)
                        commonArea = 0;

                    return area1 + area2 - commonArea;
            }

};

int main(){
        Solution s;
//        int a = -1294967294;
        int a=-1500000001, b=0, c=-1500000000, d=1, e=1500000000, f=0, g=1500000001, h=1;
//        cout<<a<<endl;
        int res = s.computeArea(a,b,c,d,e,f,g,h);
        cout<<res<<endl;
        return 0;

}
