#include <conio.h>
#include "../Header Files/Controls.h"

char getKey() {
    int c, ex;
    while (1) {
        c = _getch();
        if (c == 'q' || c == 'Q') return c;
        if (c && c != 224)
            return NULL;
        else
        {
            switch (ex = _getch())
            {
            case KEY_UP:     /* H */
                return (char)KEY_UP;    //key up
            case KEY_DOWN:   /* K */
                return (char)KEY_DOWN;   // key down
            case KEY_LEFT:   /* M */
                return (char)KEY_LEFT;  // key left
            case KEY_RIGHT: /* P */
                return (char)KEY_RIGHT;  // key right
            default:
                return NULL;  // not arrow
            }
        }
    }
}