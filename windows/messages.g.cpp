// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// Autogenerated from Pigeon (v22.6.2), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#undef _HAS_EXCEPTIONS

#include "messages.g.h"

#include <flutter/basic_message_channel.h>
#include <flutter/binary_messenger.h>
#include <flutter/encodable_value.h>
#include <flutter/standard_message_codec.h>

#include <map>
#include <optional>
#include <string>

namespace camera_windows {
using flutter::BasicMessageChannel;
using flutter::CustomEncodableValue;
using flutter::EncodableList;
using flutter::EncodableMap;
using flutter::EncodableValue;

FlutterError CreateConnectionError(const std::string channel_name) {
  return FlutterError(
      "channel-error",
      "Unable to establish connection on channel: '" + channel_name + "'.",
      EncodableValue(""));
}

// PlatformMediaSettings

PlatformMediaSettings::PlatformMediaSettings(
    const PlatformResolutionPreset& resolution_preset, bool enable_audio)
    : resolution_preset_(resolution_preset), enable_audio_(enable_audio) {}

PlatformMediaSettings::PlatformMediaSettings(
    const PlatformResolutionPreset& resolution_preset,
    const int64_t* frames_per_second, const int64_t* video_bitrate,
    const int64_t* audio_bitrate, bool enable_audio)
    : resolution_preset_(resolution_preset),
      frames_per_second_(frames_per_second
                             ? std::optional<int64_t>(*frames_per_second)
                             : std::nullopt),
      video_bitrate_(video_bitrate ? std::optional<int64_t>(*video_bitrate)
                                   : std::nullopt),
      audio_bitrate_(audio_bitrate ? std::optional<int64_t>(*audio_bitrate)
                                   : std::nullopt),
      enable_audio_(enable_audio) {}

const PlatformResolutionPreset& PlatformMediaSettings::resolution_preset()
    const {
  return resolution_preset_;
}

void PlatformMediaSettings::set_resolution_preset(
    const PlatformResolutionPreset& value_arg) {
  resolution_preset_ = value_arg;
}

const int64_t* PlatformMediaSettings::frames_per_second() const {
  return frames_per_second_ ? &(*frames_per_second_) : nullptr;
}

void PlatformMediaSettings::set_frames_per_second(const int64_t* value_arg) {
  frames_per_second_ =
      value_arg ? std::optional<int64_t>(*value_arg) : std::nullopt;
}

void PlatformMediaSettings::set_frames_per_second(int64_t value_arg) {
  frames_per_second_ = value_arg;
}

const int64_t* PlatformMediaSettings::video_bitrate() const {
  return video_bitrate_ ? &(*video_bitrate_) : nullptr;
}

void PlatformMediaSettings::set_video_bitrate(const int64_t* value_arg) {
  video_bitrate_ =
      value_arg ? std::optional<int64_t>(*value_arg) : std::nullopt;
}

void PlatformMediaSettings::set_video_bitrate(int64_t value_arg) {
  video_bitrate_ = value_arg;
}

const int64_t* PlatformMediaSettings::audio_bitrate() const {
  return audio_bitrate_ ? &(*audio_bitrate_) : nullptr;
}

void PlatformMediaSettings::set_audio_bitrate(const int64_t* value_arg) {
  audio_bitrate_ =
      value_arg ? std::optional<int64_t>(*value_arg) : std::nullopt;
}

void PlatformMediaSettings::set_audio_bitrate(int64_t value_arg) {
  audio_bitrate_ = value_arg;
}

bool PlatformMediaSettings::enable_audio() const { return enable_audio_; }

void PlatformMediaSettings::set_enable_audio(bool value_arg) {
  enable_audio_ = value_arg;
}

EncodableList PlatformMediaSettings::ToEncodableList() const {
  EncodableList list;
  list.reserve(5);
  list.push_back(CustomEncodableValue(resolution_preset_));
  list.push_back(frames_per_second_ ? EncodableValue(*frames_per_second_)
                                    : EncodableValue());
  list.push_back(video_bitrate_ ? EncodableValue(*video_bitrate_)
                                : EncodableValue());
  list.push_back(audio_bitrate_ ? EncodableValue(*audio_bitrate_)
                                : EncodableValue());
  list.push_back(EncodableValue(enable_audio_));
  return list;
}

PlatformMediaSettings PlatformMediaSettings::FromEncodableList(
    const EncodableList& list) {
  PlatformMediaSettings decoded(std::any_cast<const PlatformResolutionPreset&>(
                                    std::get<CustomEncodableValue>(list[0])),
                                std::get<bool>(list[4]));
  auto& encodable_frames_per_second = list[1];
  if (!encodable_frames_per_second.IsNull()) {
    decoded.set_frames_per_second(
        std::get<int64_t>(encodable_frames_per_second));
  }
  auto& encodable_video_bitrate = list[2];
  if (!encodable_video_bitrate.IsNull()) {
    decoded.set_video_bitrate(std::get<int64_t>(encodable_video_bitrate));
  }
  auto& encodable_audio_bitrate = list[3];
  if (!encodable_audio_bitrate.IsNull()) {
    decoded.set_audio_bitrate(std::get<int64_t>(encodable_audio_bitrate));
  }
  return decoded;
}

// PlatformSize

PlatformSize::PlatformSize(double width, double height)
    : width_(width), height_(height) {}

double PlatformSize::width() const { return width_; }

void PlatformSize::set_width(double value_arg) { width_ = value_arg; }

double PlatformSize::height() const { return height_; }

void PlatformSize::set_height(double value_arg) { height_ = value_arg; }

EncodableList PlatformSize::ToEncodableList() const {
  EncodableList list;
  list.reserve(2);
  list.push_back(EncodableValue(width_));
  list.push_back(EncodableValue(height_));
  return list;
}

PlatformSize PlatformSize::FromEncodableList(const EncodableList& list) {
  PlatformSize decoded(std::get<double>(list[0]), std::get<double>(list[1]));
  return decoded;
}

PigeonInternalCodecSerializer::PigeonInternalCodecSerializer() {}

EncodableValue PigeonInternalCodecSerializer::ReadValueOfType(
    uint8_t type, flutter::ByteStreamReader* stream) const {
  switch (type) {
    case 129: {
      const auto& encodable_enum_arg = ReadValue(stream);
      const int64_t enum_arg_value =
          encodable_enum_arg.IsNull() ? 0 : encodable_enum_arg.LongValue();
      return encodable_enum_arg.IsNull()
                 ? EncodableValue()
                 : CustomEncodableValue(
                       static_cast<PlatformResolutionPreset>(enum_arg_value));
    }
    case 130: {
      return CustomEncodableValue(PlatformMediaSettings::FromEncodableList(
          std::get<EncodableList>(ReadValue(stream))));
    }
    case 131: {
      return CustomEncodableValue(PlatformSize::FromEncodableList(
          std::get<EncodableList>(ReadValue(stream))));
    }
    default:
      return flutter::StandardCodecSerializer::ReadValueOfType(type, stream);
  }
}

void PigeonInternalCodecSerializer::WriteValue(
    const EncodableValue& value, flutter::ByteStreamWriter* stream) const {
  if (const CustomEncodableValue* custom_value =
          std::get_if<CustomEncodableValue>(&value)) {
    if (custom_value->type() == typeid(PlatformResolutionPreset)) {
      stream->WriteByte(129);
      WriteValue(EncodableValue(static_cast<int>(
                     std::any_cast<PlatformResolutionPreset>(*custom_value))),
                 stream);
      return;
    }
    if (custom_value->type() == typeid(PlatformMediaSettings)) {
      stream->WriteByte(130);
      WriteValue(
          EncodableValue(std::any_cast<PlatformMediaSettings>(*custom_value)
                             .ToEncodableList()),
          stream);
      return;
    }
    if (custom_value->type() == typeid(PlatformSize)) {
      stream->WriteByte(131);
      WriteValue(
          EncodableValue(
              std::any_cast<PlatformSize>(*custom_value).ToEncodableList()),
          stream);
      return;
    }
  }
  flutter::StandardCodecSerializer::WriteValue(value, stream);
}

/// The codec used by CameraApi.
const flutter::StandardMessageCodec& CameraApi::GetCodec() {
  return flutter::StandardMessageCodec::GetInstance(
      &PigeonInternalCodecSerializer::GetInstance());
}

// Sets up an instance of `CameraApi` to handle messages through the
// `binary_messenger`.
void CameraApi::SetUp(flutter::BinaryMessenger* binary_messenger,
                      CameraApi* api) {
  CameraApi::SetUp(binary_messenger, api, "");
}

void CameraApi::SetUp(flutter::BinaryMessenger* binary_messenger,
                      CameraApi* api,
                      const std::string& message_channel_suffix) {
  const std::string prepended_suffix =
      message_channel_suffix.length() > 0
          ? std::string(".") + message_channel_suffix
          : "";
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.getAvailableCameras" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              ErrorOr<EncodableList> output = api->GetAvailableCameras();
              if (output.has_error()) {
                reply(WrapError(output.error()));
                return;
              }
              EncodableList wrapped;
              wrapped.push_back(EncodableValue(std::move(output).TakeValue()));
              reply(EncodableValue(std::move(wrapped)));
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.create" + prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_name_arg = args.at(0);
              if (encodable_camera_name_arg.IsNull()) {
                reply(WrapError("camera_name_arg unexpectedly null."));
                return;
              }
              const auto& camera_name_arg =
                  std::get<std::string>(encodable_camera_name_arg);
              const auto& encodable_settings_arg = args.at(1);
              if (encodable_settings_arg.IsNull()) {
                reply(WrapError("settings_arg unexpectedly null."));
                return;
              }
              const auto& settings_arg =
                  std::any_cast<const PlatformMediaSettings&>(
                      std::get<CustomEncodableValue>(encodable_settings_arg));
              api->Create(camera_name_arg, settings_arg,
                          [reply](ErrorOr<int64_t>&& output) {
                            if (output.has_error()) {
                              reply(WrapError(output.error()));
                              return;
                            }
                            EncodableList wrapped;
                            wrapped.push_back(
                                EncodableValue(std::move(output).TakeValue()));
                            reply(EncodableValue(std::move(wrapped)));
                          });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.initialize" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              api->Initialize(
                  camera_id_arg, [reply](ErrorOr<PlatformSize>&& output) {
                    if (output.has_error()) {
                      reply(WrapError(output.error()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(
                        CustomEncodableValue(std::move(output).TakeValue()));
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.dispose" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              std::optional<FlutterError> output = api->Dispose(camera_id_arg);
              if (output.has_value()) {
                reply(WrapError(output.value()));
                return;
              }
              EncodableList wrapped;
              wrapped.push_back(EncodableValue());
              reply(EncodableValue(std::move(wrapped)));
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.takePicture" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              api->TakePicture(
                  camera_id_arg, [reply](ErrorOr<std::string>&& output) {
                    if (output.has_error()) {
                      reply(WrapError(output.error()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(
                        EncodableValue(std::move(output).TakeValue()));
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.startVideoRecording" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              api->StartVideoRecording(
                  camera_id_arg, [reply](std::optional<FlutterError>&& output) {
                    if (output.has_value()) {
                      reply(WrapError(output.value()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(EncodableValue());
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.stopVideoRecording" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              api->StopVideoRecording(
                  camera_id_arg, [reply](ErrorOr<std::string>&& output) {
                    if (output.has_error()) {
                      reply(WrapError(output.error()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(
                        EncodableValue(std::move(output).TakeValue()));
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.startImageStream" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              std::optional<FlutterError> output =
                  api->StartImageStream(camera_id_arg);
              if (output.has_value()) {
                reply(WrapError(output.value()));
                return;
              }
              EncodableList wrapped;
              wrapped.push_back(EncodableValue());
              reply(EncodableValue(std::move(wrapped)));
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.stopImageStream" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              std::optional<FlutterError> output =
                  api->StopImageStream(camera_id_arg);
              if (output.has_value()) {
                reply(WrapError(output.value()));
                return;
              }
              EncodableList wrapped;
              wrapped.push_back(EncodableValue());
              reply(EncodableValue(std::move(wrapped)));
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.pausePreview" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              api->PausePreview(camera_id_arg,
                                [reply](std::optional<FlutterError>&& output) {
                                  if (output.has_value()) {
                                    reply(WrapError(output.value()));
                                    return;
                                  }
                                  EncodableList wrapped;
                                  wrapped.push_back(EncodableValue());
                                  reply(EncodableValue(std::move(wrapped)));
                                });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.camera_windows.CameraApi.resumePreview" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_camera_id_arg = args.at(0);
              if (encodable_camera_id_arg.IsNull()) {
                reply(WrapError("camera_id_arg unexpectedly null."));
                return;
              }
              const int64_t camera_id_arg = encodable_camera_id_arg.LongValue();
              api->ResumePreview(camera_id_arg,
                                 [reply](std::optional<FlutterError>&& output) {
                                   if (output.has_value()) {
                                     reply(WrapError(output.value()));
                                     return;
                                   }
                                   EncodableList wrapped;
                                   wrapped.push_back(EncodableValue());
                                   reply(EncodableValue(std::move(wrapped)));
                                 });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
}

EncodableValue CameraApi::WrapError(std::string_view error_message) {
  return EncodableValue(
      EncodableList{EncodableValue(std::string(error_message)),
                    EncodableValue("Error"), EncodableValue()});
}

EncodableValue CameraApi::WrapError(const FlutterError& error) {
  return EncodableValue(EncodableList{EncodableValue(error.code()),
                                      EncodableValue(error.message()),
                                      error.details()});
}

// Generated class from Pigeon that represents Flutter messages that can be
// called from C++.
CameraEventApi::CameraEventApi(flutter::BinaryMessenger* binary_messenger)
    : binary_messenger_(binary_messenger), message_channel_suffix_("") {}

CameraEventApi::CameraEventApi(flutter::BinaryMessenger* binary_messenger,
                               const std::string& message_channel_suffix)
    : binary_messenger_(binary_messenger),
      message_channel_suffix_(message_channel_suffix.length() > 0
                                  ? std::string(".") + message_channel_suffix
                                  : "") {}

const flutter::StandardMessageCodec& CameraEventApi::GetCodec() {
  return flutter::StandardMessageCodec::GetInstance(
      &PigeonInternalCodecSerializer::GetInstance());
}

void CameraEventApi::CameraClosing(
    std::function<void(void)>&& on_success,
    std::function<void(const FlutterError&)>&& on_error) {
  const std::string channel_name =
      "dev.flutter.pigeon.camera_windows.CameraEventApi.cameraClosing" +
      message_channel_suffix_;
  BasicMessageChannel<> channel(binary_messenger_, channel_name, &GetCodec());
  EncodableValue encoded_api_arguments = EncodableValue();
  channel.Send(
      encoded_api_arguments, [channel_name, on_success = std::move(on_success),
                              on_error = std::move(on_error)](
                                 const uint8_t* reply, size_t reply_size) {
        std::unique_ptr<EncodableValue> response =
            GetCodec().DecodeMessage(reply, reply_size);
        const auto& encodable_return_value = *response;
        const auto* list_return_value =
            std::get_if<EncodableList>(&encodable_return_value);
        if (list_return_value) {
          if (list_return_value->size() > 1) {
            on_error(
                FlutterError(std::get<std::string>(list_return_value->at(0)),
                             std::get<std::string>(list_return_value->at(1)),
                             list_return_value->at(2)));
          } else {
            on_success();
          }
        } else {
          on_error(CreateConnectionError(channel_name));
        }
      });
}

void CameraEventApi::Error(
    const std::string& error_message_arg,
    std::function<void(void)>&& on_success,
    std::function<void(const FlutterError&)>&& on_error) {
  const std::string channel_name =
      "dev.flutter.pigeon.camera_windows.CameraEventApi.error" +
      message_channel_suffix_;
  BasicMessageChannel<> channel(binary_messenger_, channel_name, &GetCodec());
  EncodableValue encoded_api_arguments = EncodableValue(EncodableList{
      EncodableValue(error_message_arg),
  });
  channel.Send(
      encoded_api_arguments, [channel_name, on_success = std::move(on_success),
                              on_error = std::move(on_error)](
                                 const uint8_t* reply, size_t reply_size) {
        std::unique_ptr<EncodableValue> response =
            GetCodec().DecodeMessage(reply, reply_size);
        const auto& encodable_return_value = *response;
        const auto* list_return_value =
            std::get_if<EncodableList>(&encodable_return_value);
        if (list_return_value) {
          if (list_return_value->size() > 1) {
            on_error(
                FlutterError(std::get<std::string>(list_return_value->at(0)),
                             std::get<std::string>(list_return_value->at(1)),
                             list_return_value->at(2)));
          } else {
            on_success();
          }
        } else {
          on_error(CreateConnectionError(channel_name));
        }
      });
}

}  // namespace camera_windows
