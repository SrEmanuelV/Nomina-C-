#include <iostream>
#include <iomanip> // Para std::setprecision
#include <string>
using namespace std;

// Definir las constantes
const double SALARIO_MINIMO = 2600000.0;  // Salario minimo para calcular auxilio de transporte

// Funcion para calcular el salario devengado
double calcularSalarioDevengado(double salarioBase, double horasExtras, double recargosNocturnos, double trabajoDominicalFestivo, double auxilioTransporte) {
    return salarioBase + horasExtras + recargosNocturnos + trabajoDominicalFestivo + auxilioTransporte;
}

// Funcion para calcular el total devengado
double calcularTotalDevengado(double salarioDevengado) {
    return salarioDevengado; // En este caso, el total devengado es igual al salario devengado
}

// Funcion para calcular el neto pagado
double calcularNetoPagado(double totalDevengado, double salud, double pension, double retencionFuente, double otrasDeducciones) {
    return totalDevengado - (salud + pension + retencionFuente + otrasDeducciones);
}

int main() {
    string nombre;
    double salarioBase, diasLiquidados, horasExtras, recargosNocturnos;
    double trabajoDominicalFestivo, auxilioTransporte, salud, pension, retencionFuente, otrasDeducciones;
    char opcion;

    do {
        // Pedir datos al usuario
        cout << "Ingrese el nombre del empleado: ";
        getline(cin, nombre);

        cout << "Ingrese el salario base: ";
        cin >> salarioBase;

        cout << "Ingrese los dias liquidados: ";
        cin >> diasLiquidados;

        cout << "Ingrese las horas extras trabajadas: ";
        double horasExtrasTrabajadas;
        cin >> horasExtrasTrabajadas;

        cout << "Ingrese el valor por hora extra: ";
        double valorHoraExtra;
        cin >> valorHoraExtra;
        horasExtras = horasExtrasTrabajadas * valorHoraExtra;

        cout << "Ingrese el valor de los recargos nocturnos: ";
        cin >> recargosNocturnos;

        cout << "Ingrese el valor del trabajo dominical y festivo: ";
        cin >> trabajoDominicalFestivo;

        if (salarioBase > SALARIO_MINIMO) {
            // No se requiere el auxilio de transporte si el salario es mayor al minimo
            auxilioTransporte = 0;
        } else {
            cout << "Ingrese el auxilio de transporte: ";
            cin >> auxilioTransporte;
        }

        double salarioDevengado = calcularSalarioDevengado(salarioBase, horasExtras, recargosNocturnos, trabajoDominicalFestivo, auxilioTransporte);
        double totalDevengado = calcularTotalDevengado(salarioDevengado);

        cout << "Ingrese el valor de la salud: ";
        cin >> salud;

        cout << "Ingrese el valor de la pension: ";
        cin >> pension;

        cout << "Ingrese la retencion en la fuente: ";
        cin >> retencionFuente;

        cout << "Ingrese otras deducciones: ";
        cin >> otrasDeducciones;

        double netoPagado = calcularNetoPagado(totalDevengado, salud, pension, retencionFuente, otrasDeducciones);

        // Mostrar resultados
        cout << fixed << setprecision(2); // Configurar el formato para los decimales
        cout << "\n--- Resultados ---" << endl;
        cout << "Nombre del empleado: " << nombre << endl;
        cout << "Salario Devengado: " << salarioDevengado << " COP" << endl;
        cout << "Total Devengado: " << totalDevengado << " COP" << endl;
        cout << "Neto Pagado: " << netoPagado << " COP" << endl;

        // Preguntar si se desea ingresar otro empleado
        cout << "\nDesea ingresar otro empleado? (s/n): ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

    } while (opcion == 's' || opcion == 'S');

    cout << "Programa terminado." << endl;
    return 0;
}


