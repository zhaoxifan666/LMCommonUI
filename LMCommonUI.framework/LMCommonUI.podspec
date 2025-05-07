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
  spec.ios.deployment_target = "11.0"
  spec.swift_version = "5.0"


  spec.description  = <<-DESC
  通用UI组件库，缓慢迁移
                   DESC

  spec.homepage     = "http://git.aqara.com/aqara-app/sdk/commonui/commonui_ios"


  spec.license      = "MIT"


  spec.author             = { "Silver" => "maoqun.lin-a1756@aqara.com" }
  # Or just: spec.author    = "Silver"
  # spec.authors            = { "Silver" => "maoqun.lin-a1756@aqara.com" }

  spec.source       = { :git => "http://git.aqara.com/aqara-app/sdk/commonui/commonui_ios.git", :tag => "#{spec.version}" }


  spec.source_files  = "LMCommonUI", "LMCommonUI/**/*.{h,m}"
  spec.exclude_files = "Classes/Exclude"

  spec.public_header_files = "LMCommonUI/**/*.h"

  spec.prefix_header_file = false
  spec.prefix_header_file = 'LMCommonUI/PrefixHeader.pch'
  spec.resource =  'LMCommonUI/LMCommonUI.bundle'


  spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  spec.dependency "Masonry"
  spec.dependency "LMFramework"
  spec.dependency "ReactiveObjC"
  spec.dependency "TTTAttributedLabel"
  spec.dependency 'MJRefresh'
 spec.dependency "SDWebImage", "~> 5.9.1"
end
