/*
 * factorial_calculator.h
 *
 *  Created on: Dec 1, 2021
 *      Author: stas
 */
#pragma once

#include <systemc>
#include <tlm>

using namespace sc_core;

/**
 * fact_calc gets a request to calculate the factorial of the value provided by the input signal.
 */
SC_MODULE(fact_calc) {
    sc_core::sc_in<uint32_t> input{"input"};
    sc_core::sc_out<uint64_t> output{"output"};

    SC_CTOR(fact_calc) {
        SC_THREAD(calc);
        sensitive << input;
        instance_cnt_++;
        std::cout << this->name() << ": instance " << instance_cnt_ << std::endl;
    }

    void calc() {
        uint64_t factorial{init_val_};
        while(true) {
            wait();
            value_ = input.read();
            factorial = 1;
            for(uint32_t i = 1; i <= value_; i++) {
                factorial *= i;
            }
            wait(100, SC_PS);

            output.write(factorial);
        }
    }
private:
    static uint32_t instance_cnt_;
    const uint32_t init_val_{1};
    uint32_t value_{0};
};
uint32_t fact_calc::instance_cnt_ = 0;

SC_MODULE(controller) {
    sc_core::sc_in<uint64_t> input{"input"};
    sc_core::sc_out<uint32_t> output{"output"};

    SC_CTOR(controller) {
        SC_THREAD(execute);
        sensitive << input;
    }

    void execute() {
        while(true) {
            wait(10, SC_PS);
            output.write(value_++);
            wait();
            std::cout << this->name() << ": factorial of " << output.read() << " is " << input.read() << std::endl;
        }
    }
private:
    static uint32_t value_;
};
uint32_t controller::value_ = 1;
