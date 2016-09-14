/**
 * Programa cliente solicitando data atual ao servidor.
 *
 * Figura 3.20
 *
 * @author Gagne, Galvin, Silberschatz
 * Fundamentos de Sistemas Operacionais - Oitava Edi��o.
 * Copyright John Wiley & Sons - 2011.
 */ 

import java.net.*;
import java.io.*;

public class DateClient
{
	public static void main(String[] args)  {
		try {
			// podeeria ser alterado para um nome ou endere�o IP que n�o fosse o do host local
			Socket sock = new Socket("127.0.0.1",6013);
			InputStream in = sock.getInputStream();
			BufferedReader bin = new BufferedReader(new InputStreamReader(in));

			String line;
			while( (line = bin.readLine()) != null)
				System.out.println(line);
				
			sock.close();
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
}