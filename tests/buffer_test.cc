#include <gtest/gtest.h>
#include <glog/logging.h>
#include <string>

#include "src/buffer.h"
#include "src/types.h"

TEST(BufferTest, basic_use) {
  Buffer<int> ib(10);
  ib.SetValue(0, 626);
  ib.SetValue(1, 57);

  Buffer<float> fb(20);
  fb.SetValue(0, 6.26f);
  fb.SetValue(1, 5.7f);

  Buffer<std::string> sb(12);
  sb.SetValue(0, "Zhengyu");
  sb.SetValue(1, "APi");

  std::vector<BufferBase *> buffers;
  buffers.push_back(&ib);
  buffers.push_back(&fb);
  buffers.push_back(&sb);

  switch (buffers[0]->type()) {
    case DataTypeToEnum<float>::value: {
      Buffer<float> *pb = dynamic_cast<Buffer<float> *>(buffers[0]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DataTypeToEnum<int>::value: {
      Buffer<int> *pb = dynamic_cast<Buffer<int> *>(buffers[0]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DataTypeToEnum<std::string>::value: {
      Buffer<std::string> *pb = dynamic_cast<Buffer<std::string> *>(buffers[0]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DT_INVALID: {
      LOG(INFO) << "Type not set";
      break;
    }
    default:
      LOG(INFO) << "Unexpected type";
      break;
  }

  switch (buffers[1]->type()) {
    case DataTypeToEnum<float>::value: {
      Buffer<float> *pb = dynamic_cast<Buffer<float> *>(buffers[1]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DataTypeToEnum<int>::value: {
      Buffer<int> *pb = dynamic_cast<Buffer<int> *>(buffers[1]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DataTypeToEnum<std::string>::value: {
      Buffer<std::string> *pb = dynamic_cast<Buffer<std::string> *>(buffers[1]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DT_INVALID: {
      LOG(INFO) << "Type not set";
      break;
    }
    default:
      LOG(INFO) << "Unexpected type";
      break;
  }

  switch (buffers[2]->type()) {
    case DataTypeToEnum<float>::value: {
      Buffer<float> *pb = dynamic_cast<Buffer<float> *>(buffers[2]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DataTypeToEnum<int>::value: {
      Buffer<int> *pb = dynamic_cast<Buffer<int> *>(buffers[2]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DataTypeToEnum<std::string>::value: {
      Buffer<std::string> *pb = dynamic_cast<Buffer<std::string> *>(buffers[2]);
      LOG(INFO) << pb->GetValue(0) << "\t" << pb->GetValue(1);
      break;
    }
    case DT_INVALID: {
      LOG(INFO) << "Type not set";
      break;
    }
    default:
      LOG(INFO) << "Unexpected type";
      break;
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
