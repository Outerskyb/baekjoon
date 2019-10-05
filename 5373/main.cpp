#include <iostream>

class cube {
    enum class WAY{
        PLUS=true,
        MINUS=false
    };
    int color[6][3][3]; // u d f b l r ¼ø
    cube() {
        memset(color, 0, 4 * 6 * 3 * 3);
    }
public:
    void rotate(int position, WAY porm) {
        
    }
    
};

int main() 
{

}