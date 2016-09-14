/**
 * Servidor escutando a hora do dia na porta 6013.
 *
 * Figura 3.19
 *
 * @author Gagne, Galvin, Silberschatz
 * Fundamentos de Sistemas Operacionais - Oitava Edi��o
 * Copyright John Wiley & Sons - 2011.
 */
 
import java.net.*;
import java.io.*;

public class DateServer
{
	public static void main(String[] args)  {
		try {
			ServerSocket sock = new ServerSocket(6013);

			// agora escuta conex�es
			while (true) {
				Socket client = sock.accept();
				// temos uma conex�o
				
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				// grava a data no socket
				pout.println(new java.util.Date().toString());

				// fecha o socket e volta a escutar conex�es
				client.close();
			}
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
}