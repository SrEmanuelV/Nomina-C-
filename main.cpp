#include <iostream>
#include <iomanip> // Para std::setprecision
#include <string>
using namespace std;

// Definir las constantes
const double SALARIO_MINIMO = 1300000.0; // Salario mínimo colombiano
const double AUXILIO_TRANSPORTE = 162000.0; // Valor fijo del auxilio de transporte
const double SALARIO_UMBRAL = 2 * SALARIO_MINIMO; // Umbral para pagar auxilio de transporte

// Funcion para calcular el salario devengado
double calcularSalarioDevengado(double salarioBase, double diasLiquidados) {
    return (salarioBase / 30) * diasLiquidados;
}

// Funcion para calcular el total devengado
double calcularTotalDevengado(double salarioDevengado, double horasExtras, double recargosNocturnos, double trabajoDominicalFestivo, double auxilioTransporte) {
    return salarioDevengado + horasExtras + recargosNocturnos + trabajoDominicalFestivo + auxilioTransporte;
}

// Funcion para calcular el neto pagado
double calcularNetoPagado(double totalDevengado, double salud, double pension, double retencionFuente, double otrasDeducciones) {
    return totalDevengado - (salud + pension + retencionFuente + otrasDeducciones);
}

int main() {
    string nombre;
    double salarioBase, diasLiquidados, horasExtras, recargosNocturnos;
    double trabajoDominicalFestivo, salud, pension, retencionFuente, otrasDeducciones;
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

        // Determinar si se paga el auxilio de transporte
        double auxilioTransporte = (salarioBase <= SALARIO_UMBRAL) ? AUXILIO_TRANSPORTE : 0;

        double salarioDevengado = calcularSalarioDevengado(salarioBase, diasLiquidados);
        double totalDevengado = calcularTotalDevengado(salarioDevengado, horasExtras, recargosNocturnos, trabajoDominicalFestivo, auxilioTransporte);

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
        cout << "Salario Base: " << salarioDevengado << " COP" << endl;
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
