#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    int A, B, C, D, E, F, G, H;
    cin >> A >> B >> C >> D >> E >> F >> G >> H;

    if (A + C + F + H - B - D - E - G != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    while (A + C + F + H) {

        if (A > 0) {
            if (B > 0) {
                A--;
                B--;
                cout << "AB-" << endl;
            }
            else if (D > 0) {
                A--;
                D--;
                cout << "AD-" << endl;
            }
            else if (E > 0) {
                A--;
                E--;
                cout << "AE-" << endl;
            }
            else if (G > 0) {
                A--;
                G--;
                cout << "BC+" << endl << "CG-" << endl << "AB-" << endl;
            }
        }

        if (C > 0) {
            if (B > 0) {
                B--;
                C--;
                cout << "BC-" << endl;
            }
            else if (D > 0) {
                C--;
                D--;
                cout << "CD-" << endl;
            }
            else if (G > 0) {
                C--;
                G--;
                cout << "GC-" << endl;
            }
            else if (E > 0) {
                C--;
                E--;
                cout << "AB+" << endl << "AE-" << endl << "BC-" << endl;
            }
        }

        if (F > 0) {
            if (B > 0) {
                B--;
                F--;
                cout << "BF-" << endl;
            }
            else if (E > 0) {
                E--;
                F--;
                cout << "FE-" << endl;
            }
            else if (G > 0) {
                F--;
                G--;
                cout << "FG-" << endl;
            }
            else if (D > 0) {
                F--;
                D--;
                cout << "EH+" << endl << "HD-" << endl << "EF-" << endl;
            }
        }

        if (H > 0) {
            if (D > 0) {
                D--;
                H--;
                cout << "DH-" << endl;
            }
            else if (E > 0) {
                H--;
                E--;
                cout << "HE-" << endl;
            }
            else if (G > 0) {
                H--;
                G--;
                cout << "HG-" << endl;
            }
            else if (B > 0) {
                H--;
                B--;
                cout << "EF+" << endl << "FB-" << endl << "HE-" << endl;
            }
        }
    }

    return 0;
}