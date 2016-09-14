/**
 * Esse programa cria um processo separado usando a chamada se sistema CreateProcess().
 *
 * Figura 3.12
 *
 * @author Gagne, Galvin, Silberschatz
 * Fundamentos de Sistemas Operacionais - Oitava Edição
 * Copyright John Wiley & Sons - 2011.
 */
 
#include <windows.h>
#include <stdio.h>

int main( VOID )
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    // Inicia o processo filho.
    if( !CreateProcess( NULL,   // Sem nome de módulo (usa linha de comando).
        "C:\\WINDOWS\\system32\\mspaint.exe", // Linha de comando.
        NULL,             // Identificador de processo não é herdado.
        NULL,             // Identificador de thread não é herdado.
        FALSE,            // Configura a herança do identificador com FALSE.
        0,                // sem flags de criação.
        NULL,             // Usa bloco de ambiente do pai.
        NULL,             // Usa diretório inicial do pai.
        &si,              // Ponteiro da estrutura STARTUPINFO.
        &pi )             // Ponteiro da estrutura PROCESS_INFORMATION.
    )
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return -1;
    }

    // Espera até o processo filho terminar.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Fecha os identificadores do processo e do thread.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}
