#include "controller.h"
#include "cwuser.h"
#include "model.h"
#include "view.h"

int main(int argc, char* argv[]) {
    CWUser cwu;
    
    View v;

    DatabaseManager dbm(argv[0]);
    TableManager tm;
    NoteManager nm;
    Model m(dbm, tm, nm);

    Controller c(cwu, v, m);
    c.run();

    return 0;
}
