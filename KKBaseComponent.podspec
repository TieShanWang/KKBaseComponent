

Pod::Spec.new do |s|

  s.name         = "KKBaseComponent"

  s.version      = "1.0.2"

  s.summary      = "KKBaseComponent for KKKit. wish you like it"

  s.description  = <<-DESC
  KKBaseComponent for KKKit. It contains some tools or baseModel and so on
  ->1.0.0 add more category
                   DESC

  s.homepage     = "https://github.com/TieShanWang/KKBaseComponent"

  s.license      = "MIT"

  s.author             = { "wangtieshan" => "15003836653@163.com" }

  s.platform     = :ios, "7.0"

  s.source       = { :git => "https://github.com/TieShanWang/KKBaseComponent.git", :tag => "1.0.2" }

  s.source_files  = "KKBaseComponent/KKBaseComponent/**/*.{h,m,mm}","KKBaseComponent/KKBaseComponent/*.{h,m,mm}"

  s.framework  = "UIKit"

 s.requires_arc = true

end
