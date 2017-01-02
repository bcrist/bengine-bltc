#pragma once
#ifndef BE_BLTC_BLTC_APP_HPP_
#define BE_BLTC_BLTC_APP_HPP_

#include <be/core/lifecycle.hpp>
#include <be/core/filesystem.hpp>

namespace be {
namespace bltc {

///////////////////////////////////////////////////////////////////////////////
class BltcApp final {
public:
   BltcApp(int argc, char** argv);

   int operator()();

private:
   enum class SourceType { path, raw, console };
   enum class DestType { path, console };

   struct Job {
      S source;
      S dest;
      SourceType source_type;
      DestType dest_type;
   };

   void process_(Job& job);
   void process_path_(const Path& path, Job& job);
   void process_non_path_(const S& data, Job& job);
   void process_raw_(const S& data, Job& job);

   CoreInitLifecycle init_;
   bool debug_mode_ = false;
   I8 status_ = 0;
   std::vector<Path> search_paths_;
   std::vector<Job> jobs_;
   Path output_path_;
};

} // be::bltc
} // be

#endif
