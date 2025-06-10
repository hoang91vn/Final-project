#include "ef/DataLoader.hpp"
#include "ef/Preprocessor.hpp"
#include "ef/FeatureGenerator.hpp"
#include "ef/ARIMAModel.hpp"
#include "ef/XGBoostModel.hpp"
#include "ef/Evaluator.hpp"
#include "ef/Visualizer.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <csv> <window> <model(arima|xgb)>\n";
        return 1;
    }
    std::string csv = argv[1];
    size_t window = std::stoul(argv[2]);
    std::string modelType = argv[3];

    ef::TimeSeries ts = ef::DataLoader::loadCSV(csv);
    ef::Preprocessor::fillMissing(ts);
    ef::Preprocessor scaler;
    scaler.trainScaler(ts);
    scaler.applyScaler(ts);

    std::vector<std::vector<double>> X;
    std::vector<double> y;
    ef::FeatureGenerator::createLaggedFeatures(ts, window, X, y);

    std::unique_ptr<ef::ForecastModel> model;
    if (modelType == "arima") {
        model = std::make_unique<ef::ARIMAModel>(window,0,0);
    } else if (modelType == "xgb") {
        model = std::make_unique<ef::XGBoostModel>();
    } else {
        std::cerr << "Unknown model type\n";
        return 1;
    }

    model->train(X, y);
    std::vector<double> preds = model->predict(X);

    double rmse = ef::Evaluator::rmse(y, preds);
    double mape = ef::Evaluator::mape(y, preds);

    std::cout << "RMSE: " << rmse << " MAPE: " << mape << "%\n";

    ef::Visualizer::plot(y, preds, "forecast.png");
    std::cout << "Saved plot to forecast.png\n";
    return 0;
}
