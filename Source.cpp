#include <windows.h>
#include <string>
#include <locale.h>
#include <fstream>
#include <bitset>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include "resource.h"

using namespace std;
using std::bitset;

HWND ghDlg = 0;
HWND VRegistro;
HWND VSalir;
HWND VMenuPrincipal;

HWND AdminNombre;
HWND AdminContra;
HWND AdminComercio;

struct admins
{
    wstring adminnombre;
    wstring admincontra;
    wstring comercio;
    admins* next;
    admins* anterior;
};
admins* aux = nullptr;
admins* inicio = nullptr;
wchar_t altas[30];
wstring buscarusuario, buscarcontra, buscarcomercio;


BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Registro(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Salir(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK MenuPrincipal(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);





int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    ghDlg = CreateDialog(hInstance, MAKEINTRESOURCE(Dialogo_Iniciarsesion), 0, (DLGPROC)WindowProc);
    ShowWindow(ghDlg, nCmdShow);
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));
    while (GetMessage(&msg, 0, 0, 0))
    {
        if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}

BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_INITDIALOG:
        AdminNombre = GetDlgItem(hwnd, Edit_Admin);
        AdminContra = GetDlgItem(hwnd, Edit_contra);
        AdminComercio = GetDlgItem(hwnd, Edit_Comercio_inicio);

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case Bot_Cerrar_Iniciosesion:
            VSalir = CreateDialog(NULL, MAKEINTRESOURCE(Dialogo_salir), hwnd, (DLGPROC)Salir);
            ShowWindow(VSalir, SW_SHOW);

            break;

        case Bot_Registrar_Iniciar:
            VRegistro = CreateDialog(NULL, MAKEINTRESOURCE(Dialogo_Registro), hwnd, (DLGPROC)Registro);
            ShowWindow(VRegistro, SW_SHOW);
            break;
        case Bot_Iniciarsesion_Iniciar:
           /* admins* nuevo = new admins();
           
            bool usuarioencontrado = false;
            

            ZeroMemory(&altas, sizeof(altas));
            GetWindowText(AdminNombre, (LPWSTR)altas, 30);
            buscarusuario = wstring(altas);

            ZeroMemory(&altas, sizeof(altas));
            GetWindowText(AdminContra, (LPWSTR)altas, 30);
            buscarcontra = wstring(altas);

            ZeroMemory(&altas, sizeof(altas));
            GetWindowText(AdminComercio, (LPWSTR)altas, 30);
            buscarcomercio = wstring(altas);
        

            if (inicio != nullptr)
            {
                while (nuevo != nullptr and usuarioencontrado = false)
                {
                    if (nuevo->adminnombre == AdminNombre)
                    {

                        if (nuevo->admincontra == AdminContra)
                        {
                            if (nuevo->comercio == AdminComercio)
                            {
                                VMenuPrincipal = CreateDialog(NULL, MAKEINTRESOURCE(Dialogo_MenuPrincipal_Admins), hwnd, (DLGPROC)MenuPrincipal);
                                ShowWindow(VMenuPrincipal, SW_SHOW);
                            }
                        }


                    }
                }
            }
           */
            VMenuPrincipal = CreateDialog(NULL, MAKEINTRESOURCE(Dialogo_MenuPrincipal_Admins), hwnd, (DLGPROC)MenuPrincipal);
            ShowWindow(VMenuPrincipal, SW_SHOW);
            break;
        }

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    }

    return FALSE;
}
BOOL CALLBACK Registro(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_INITDIALOG:
        AdminNombre=GetDlgItem(hwnd, Edit_Admin_Registro);
        AdminContra = GetDlgItem(hwnd, Edit_Contra_Registro);
        AdminComercio = GetDlgItem(hwnd, Edit_Comercio_Registro);
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case Bot_Cancelar_Registro:
            EndDialog(hwnd, wParam);
            break;
        case Bot_Aceptar_Registro:
            admins* nuevo = new admins();

            ZeroMemory(&altas, sizeof(altas));
            GetWindowText(AdminNombre, (LPWSTR)altas, 30);
            nuevo->adminnombre = altas;

            ZeroMemory(&altas, sizeof(altas));
            GetWindowText(AdminContra, (LPWSTR)altas, 30);
            nuevo->admincontra = altas;

            ZeroMemory(&altas, sizeof(aux));
            GetWindowText(AdminComercio, (LPWSTR)altas, 30);
            nuevo->comercio = altas;
            break;
            break;
        }
    case WM_CLOSE:
      
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    }

    return FALSE;
}
BOOL CALLBACK Salir(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_INITDIALOG:

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case Bot_Volver_salir:
            DestroyWindow(hwnd);
            break;
        case Bot_Aceptar_salir:
            DestroyWindow(hwnd);
            PostQuitMessage(0);
            break;
        }
        break;

    case WM_CLOSE:
       
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
              break;

    }

    return FALSE;

}
BOOL CALLBACK MenuPrincipal(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {

        case WM_INITDIALOG:
            

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
            case Bot_Cancelar_Registro:
               
                break;
            case Bot_Aceptar_Registro:
                break;
            }
        case WM_CLOSE:

            return 0;

        case WM_DESTROY:
            break;

        }

        return FALSE;
    }
