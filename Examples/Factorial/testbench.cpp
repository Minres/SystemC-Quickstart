/*
 * testbench.cpp
 *
 *  A simple design that will be used to develop Thread-Safety-Analyzer
 */

#include "factorial_calculator.h"

using namespace std;
using namespace sc_core;

int sc_main(int argc, char* argv[]) //< main entry-point to SystemC
{
    sc_signal<uint32_t> request1("request1");
    sc_signal<uint64_t> result1("result1");
    sc_signal<uint32_t> request2("request2");
    sc_signal<uint64_t> result2("result2");

    fact_calc factorial1("factorial1");
    controller ctrl1("ctrl1");
    fact_calc factorial2("factorial2");
    controller ctrl2("ctrl2");

    factorial1.input(request1);
    factorial1.output(result1);
    ctrl1.input(result1);
    ctrl1.output(request1);
    factorial2.input(request2);
    factorial2.output(result2);
    ctrl2.input(result2);
    ctrl2.output(request2);

    // run the simulation
    sc_start(1, SC_NS);
    sc_stop();
    return 0;
}
