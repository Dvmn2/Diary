#include "controller.h"
#include "cwuser.h"
#include "model.h"
#include "view.h"

int main() {
    CWUser cwu;
    View v;
    Model m;
    Controller c(&cwu, &v, &m);
    c.run();

    return 0;
}
