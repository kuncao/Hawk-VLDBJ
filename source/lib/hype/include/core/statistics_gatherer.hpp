/***********************************************************************************************************
Copyright (c) 2012, Sebastian Breß, Otto-von-Guericke University of Magdeburg,
Germany. All rights reserved.

This program and accompanying materials are made available under the terms of
the
GNU LESSER GENERAL PUBLIC LICENSE - Version 3,
http://www.gnu.org/licenses/lgpl-3.0.txt
***********************************************************************************************************/
#pragma once

#include <cassert>
#include <config/exports.hpp>
#include <core/workload_generator.hpp>

/* temporarily disable warnings because of missing STL DLL interface */
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4251)
#endif

namespace hype {
  namespace core {
    class HYPE_EXPORT StatisticsGatherer {
     public:
      StatisticsGatherer(const std::string& operation_name);

      bool addStatistics(const WorkloadGenerator& w);

      void printReport() const throw();

     private:
      std::string operation_name_;
      unsigned int number_of_right_decisions_;
      unsigned int number_of_total_decisions_;
      /*! \brief stores total time algorithm i would have taken for the whole
       * workload, if only algorithm i would be choosen (models static models)*/
      std::vector<double> isolated_execution_time_of_algorithms_;
      std::vector<std::string> names_of_algorithms_;
      // reference models
      double execution_time_of_ideal_model_;
      double execution_time_of_cpu_only_model_;
      double execution_time_of_gpu_only_model_;
      // for real model
      double execution_time_of_real_model_;
      double total_time_for_overhead_of_addObservation_;
      double total_time_for_overhead_of_getOptimalAlgorithm_;
      // Feature: inter device parallelism
      double inter_device_parallel_time_cpu_;
      double inter_device_parallel_time_gpu_;
    };

  }  // end namespace core
}  // end namespace hype

#ifdef _MSC_VER
#pragma warning(pop)
#endif
