#include "controller.h"
#include "cwuser.h"
#include "model.h"
#include "view.h"

int main(int argc, char* argv[]) {
    CWUser cwu;
    View v;
    Model m(argv[0]);
    Controller c(&cwu, &v, &m);
    c.run();

    return 0;
}
