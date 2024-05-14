import java.util.Scanner;

import iuNew.Terminplaner;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) {
		Terminplaner planer = new Terminplaner();
		Scanner scanner = new Scanner(System.in);
		
		while (true) {
			System.out.println("Terminplaner");
			System.out.println("1. Neuen Termin hinzufügen");
			System.out.println("2. Termin anzeigen");
			System.out.println("3. Termin löschen");
			System.out.println("4. Termin bearbeiten");
			System.out.println("5. Beenden");
			
			int wahl = scanner.nextInt();
			scanner.nextLine(); //Puffer leeren
			
			switch (wahl) {
				case 1:
					planer.neuerTermin(scanner);
					//Neuen Termin hinzufügen
					break; 
				case 2:
					planer.terminAnzeigen(scanner);
					//Termin anzeigen
					break;
				case 3:
					planer.terminLoeschen(scanner);
					//Termin löschen
					break;
				case 4:
					planer.terminBearbeiten(scanner);
					break;
				case 5:
					System.out.println("Programm beendet");	
					scanner.close();
					System.exit(0);
				default:
					System.out.println("Ungültige Eingabe.");
			}
		}
	}
}
