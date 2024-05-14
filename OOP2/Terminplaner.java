package iuNew;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Termin {
	private final LocalDate datum;
	private LocalTime uhrzeit;
	private String titel;
	private String beschreibung;
	
	public Termin(LocalDate datum, LocalTime uhrzeit, String titel, String beschreibung) {
		this.datum = datum;
		this.uhrzeit = uhrzeit;
		this.titel = titel;
		this.beschreibung = beschreibung;
	}
	public LocalDate getDatum() {
		return datum;
	}
	
	public LocalTime getUhrzeit() {
		return uhrzeit;
	}
	
	public String getTitel() {
		return titel;
	}
	
	public String getBeschreibung() {
		return beschreibung;
	}
}


public class Terminplaner {
	private List<Termin> termine;
	
	public Terminplaner() {
		this.termine = new ArrayList<>();
	}
	
	public void neuerTermin(Scanner scanner) {
		System.out.println("Neuen Termin hinzufügen");
		System.out.println("Datum (JJJJ-MM-TT): ");
		String datumString = scanner.nextLine();
		LocalDate datum = LocalDate.parse(datumString);
		
		System.out.println("Uhrzeit (HH:MM): ");
		String uhrzeitString = scanner.nextLine();
		LocalTime uhrzeit = LocalTime.parse(uhrzeitString);
		
		System.out.println("Titel: ");
		String titel = scanner.nextLine();
		
		System.out.println("Beschreibung: ");
		String beschreibung = scanner.nextLine();
		
		Termin neuerTermin = new Termin(datum, uhrzeit, titel, beschreibung);
		termine.add(neuerTermin);
		System.out.println("Termin erfolgreich hinzugefügt!");
	}
	
	public void terminAnzeigen(Scanner scanner) {
		if (termine.isEmpty()) {
			System.out.println("Es gibt keine Termine.");
			return;
		}
		
		System.out.println("Alle Termine:");
		for (Termin termin : termine) {
			System.out.println("- " + termin.getDatum() + " " + termin.getUhrzeit() + ": " + termin.getTitel() + " - " + termin.getBeschreibung());
		}
	}
	
	public void terminLoeschen(Scanner scanner) {
		if (termine.isEmpty()) {
			System.out.println("Es gibt keine Termine.");
			return;
		}
		
		System.out.println("Termin löschen:");
		terminAnzeigen(scanner);
		
		System.out.print("Geben Sie die Bezeichnung des zu löschenden Termins ein: ");
		String terminBezeichnung = scanner.nextLine();
		
		boolean terminGefunden = false;
		for (int i = 0; i < termine.size(); i++) {
			Termin termin = termine.get(i);
			if (terminBezeichnung.equals(termin.getTitel())) {
				termine.remove(i);
				System.out.println("Termin \"" + termin.getTitel() + "\" erfolgreich gelöscht!");
				terminGefunden = true;
				break;
			}
		}
		
		if (!terminGefunden) {
			System.out.println("Kein Termin mit der Bezeichnung \"" + terminBezeichnung + "\" gefunden.");
		}
	}
	
	public void terminBearbeiten(Scanner scanner) {
		if (termine.isEmpty()) {
			System.out.println("Es gibt keine Termine.");
			return;
		}
		
		System.out.println("Termin bearbeiten:");
		terminAnzeigen(scanner);
		
		System.out.println("GebenSie die Bezeichnung des zu bearbeitenden Termins ein: ");
		String terminBezeichnung = scanner.nextLine();
		
		boolean terminGefunden = false;
		for (int i = 0; i < termine.size(); i++) {
			Termin termin = termine.get(i);
			if (terminBezeichnung.equals(termin.getTitel())) {
				System.out.println("Aktuelle Informationen:");
				System.out.println("- Datum: " + termin.getDatum());
				System.out.println("- Uhrzeit: " + termin.getUhrzeit());
				System.out.println("- Titel: " + termin.getTitel());
				System.out.println("- Beschreibung: " + termin.getBeschreibung());
				
				System.out.println("\nGeben Sie die neuen Informationen ein:");
				System.out.println("Neues Datum (JJJJ-MM-TT): ");
				String neuesDatumString = scanner.nextLine();
				LocalDate neuesDatum = LocalDate.parse(neuesDatumString);
				
				System.out.println("Neue Uhrzeit (HH:MM): ");
				String neueUhrzeitString = scanner.nextLine();
				LocalTime neueUhrzeit = LocalTime.parse(neueUhrzeitString);
				
				System.out.println("Neuer Titel: ");
				String neuerTitel = scanner.nextLine();
				
				System.out.println("Neue Beschreibung: ");
				String neueBeschreibung = scanner.nextLine();
				
				termin.setDatum(neuesDatum);
				termin.setUhrzeit(neueUhrzeit);
				termin.setTitel(neuerTitel);
				termin.setBeschreibung(neueBeschreibung);
				
				System.out.println("Termin \"" + terminBezeichnung + "\" erfolgreich bearbeitet!");
				terminGefunden = true;
				break;
			}
		}
		
		if (!terminGefunden) {
			System.out.println("Kein Termin mit der Bezeichnung \"" + terminBezeichnung + "\" gefunden.");
		}
	}

}
