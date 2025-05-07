#
#  Be sure to run `pod spec lint LMCommonUI.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|


  spec.name         = "LMCommonUI"
  spec.version      = "1.0.0"
  spec.summary      = "通用UI组件库."
  spec.platform     = :ios, "12.0"
  spec.swift_version = "5.0"


  spec.description  = <<-DESC
  通用UI组件库，缓慢迁移
                   DESC

  spec.homepage     = "https://github.com/zhaoxifan666/LMCommonUI"


  spec.license      = "MIT"


  spec.author             = { "zhaoxifan" => "xifan.zhao@aqara.com" }
  # Or just: spec.author    = "Silver"
  # spec.authors            = { "Silver" => "maoqun.lin-a1756@aqara.com" }

  spec.source       = { :git => "https://github.com/zhaoxifan666/LMCommonUI.git", :tag => "#{spec.version}" }


  spec.vendored_frameworks = "LMCommonUI.framework"


  spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  spec.dependency "Masonry"
  spec.dependency "LMFramework", "1.0.0"
  spec.dependency "ReactiveObjC"
  spec.dependency "TTTAttributedLabel"
  spec.dependency 'MJRefresh'
 spec.dependency "SDWebImage", "~> 5.9.1"
end
