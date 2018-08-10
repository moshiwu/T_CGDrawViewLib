#
# Be sure to run `pod lib lint ZJ_CGDrawViewLib.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'T_CGDrawViewLib'
  s.version          = '0.1.1'
  s.summary          = '画笔工具'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/moshiwu/T_CGDrawViewLib'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'krystalNa' => 'liuna@raintai.com' }
  s.source           = { :git => 'https://github.com/moshiwu/T_CGDrawViewLib.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'

  s.source_files = ['ZJ_CGDrawViewLib/Classes/CGDrawView.h','ZJ_CGDrawViewLib/Classes/MLTunesOperateModel.h','ZJ_CGDrawViewLib/Classes/MLTunesOperateModel.m','ZJ_CGDrawViewLib/Classes/lame.h']
  
  s.vendored_libraries = 'ZJ_CGDrawViewLib/Classes/libmp3lame.a'
  s.frameworks = 'Foundation', 'UIKit'
end
