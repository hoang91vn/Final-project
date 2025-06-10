#include "fred_loader.hpp"
#include "data_cleaner.hpp"
#include "forecast.hpp"
#include "output_writer.hpp"
#include "plot.hpp"
#include "utils.hpp"
#include <chrono>
#include <iostream>

int main() {
    const std::string api_key = "1868e18596ed3625c987d2b148accbed";
    auto icsa = load_fred_series("ICSA", api_key);
    auto unrate = load_fred_series("UNRATE", api_key);
    auto jtsjol = load_fred_series("JTSJOL", api_key);

    auto merged = merge_series(icsa, unrate, jtsjol, "2018-01-01", "2023-12-31");

    std::vector<std::string> dates;
    std::vector<double> icsa_vals;
    for(const auto& [d,row] : merged) {
        dates.push_back(d);
        icsa_vals.push_back(row.icsa);
    }
    auto trend = utils::moving_average(icsa_vals,4);

    auto start = std::chrono::steady_clock::now();
    auto sma = forecast_sma(icsa_vals,4,3);
    auto end = std::chrono::steady_clock::now();
    std::cout << "SMA forecast time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "ms\n";

    start = std::chrono::steady_clock::now();
    auto exp = forecast_exp(icsa_vals,0.2,3);
    end = std::chrono::steady_clock::now();
    std::cout << "EXP forecast time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "ms\n";

    std::vector<std::string> fdates;
    std::string last = dates.back();
    for(size_t i=1;i<=3;++i) fdates.push_back(utils::add_days(last,7*i));

    write_forecast_csv("output/forecast.csv","ICSA","SMA",fdates,sma);
    write_forecast_csv("output/forecast.csv","ICSA","EXP",fdates,exp);

    plot_series("ICSA", dates, icsa_vals, trend, fdates, sma, "output/icsa.png");

    ascii_sparkline("ICSA raw", icsa_vals);
    ascii_sparkline("ICSA trend", trend);
    ascii_sparkline("ICSA SMA", sma);
    ascii_sparkline("ICSA EXP", exp);

    return 0;
}
