// This file was automatically generated by:
//  /Users/jross/Downloads/Slicer4/Slicer4-SuperBuild-Release/SlicerExecutionModel-build/GenerateCLP/bin/GenerateCLP --InputXML /Users/jross/Downloads/ChestImagingPlatformPrivate/CommandLineTools/GenerateMedianFilteredImage/GenerateMedianFilteredImage.xml --OutputCxx /Users/jross/Downloads/ChestImagingPlatformPrivate/CommandLineTools/GenerateMedianFilteredImage/GenerateMedianFilteredImageCLP.h
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <sstream>

#include "tclap/CmdLine.h"
#include "ModuleProcessInformation.h"

#ifdef WIN32
#define Module_EXPORT __declspec(dllexport)
#else
#define Module_EXPORT 
#endif

#if defined(main) && !defined(REGISTER_TEST)
// If main defined as a preprocessor symbol, redefine it to the expected entry point.
#undef main
#define main ModuleEntryPoint

extern "C" {
  Module_EXPORT char *GetXMLModuleDescription();
  Module_EXPORT int ModuleEntryPoint(int, char*[]);
}
#endif

extern "C" {
Module_EXPORT char XMLModuleDescription[] = 
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<executable>\n"
"  <category>Examples</category>\n"
"  <title>GenerateMedianFilteredImage</title>\n"
"  <description><![CDATA[Median Filter of a CT volume]]></description>\n"
"  <version>0.0.1</version>\n"
"  <documentation-url>http://www.slicer.org/slicerWiki/index.php/Documentation/4.2/Modules/GenerateMedianFilteredImage</documentation-url>\n"
"  <license>Slicer</license>\n"
"  <contributor> Applied Chest Imaging Laboratory, Brigham and women's hospital</contributor>\n"
"  <acknowledgements>This work was partially funded ...</acknowledgements>\n"
"  <parameters>\n"
"    <double>\n"
"      <name>radiusValue</name>\n"
"      <longflag>Radius</longflag>\n"
"      <flag>r</flag>\n"
"      <label>Radius</label>\n"
"      <description><![CDATA[Median filter radius]]></description>\n"
"      <default>1.0</default>\n"
"    </double>\n"
"<integer-vector>\n"
"      <name>lowerClipValues</name>\n"
"      <longflag>lowerClipValue</longflag>\n"
"      <flag>l</flag>\n"
"      <label>lowerClipValues</label>\n"
"      <description><![CDATA[Lower clip value applied to input image before filtering. This flag should be followed by two values: the first value is the clip value and the second value is the replacement value (i.e., everything below the clip value will be assigned the replacement value)]]></description>\n"
"<default>-1224,1024</default>\n"
"    </integer-vector>\n"
"<integer-vector>\n"
"      <name>upperClipValues</name>\n"
"      <longflag>upperClipValue</longflag>\n"
"      <flag>u</flag>\n"
"      <label>upperClipValue</label>\n"
"      <description><![CDATA[Upper clip value applied to input image before filtering. This flag should be followed by two values: the first value is the clip value and the second value is the replacement value (i.e., everything below the clip value will be assigned the replacement value)]]></description>\n"
"<default>1024,1024</default>\n"
"    </integer-vector>\n"
"    <label>IO</label>\n"
"    <description><![CDATA[Input/output parameters]]></description>\n"
"    <string>\n"
"      <name>ctFileName</name>\n"
"      <label>Input Filename</label>\n"
"      <channel>input</channel>\n"
"      <flag>i</flag>\n"
"      <longflag>--inputFile</longflag>\n"
"      <description><![CDATA[Input CT file name]]></description>\n"
"      <default>q</default>\n"
"    </string>\n"
"    <string>\n"
"      <name>outputFileName</name>\n"
"      <label>Output File</label>\n"
"      <flag>o</flag>\n"
"      <longflag>--outputFile</longflag>\n"
"      <channel>output</channel>\n"
"      <description><![CDATA[Output CT file name]]></description>\n"
"      <default>q</default>\n"
"    </string>\n"
"    <directory>\n"
"      <name>ctDir</name>\n"
"      <flag>d</flag>\n"
"      <longflag>--CTDirectory</longflag>\n"
"      <label>CT Directory Data</label>\n"
"      <channel>input</channel>\n"
"      <description><![CDATA[Directory image series]]></description>\n"
"      <default>q</default>\n"
"    </directory>\n"
"  </parameters>\n"
"</executable>\n"
;

}

void
splitString (const std::string &text,
             const std::string &separators,
             std::vector<std::string> &words)
{
  const std::string::size_type n = text.length();
  std::string::size_type start = text.find_first_not_of(separators);
  while (start < n)
    {
    std::string::size_type stop = text.find_first_of(separators, start);
    if (stop > n) stop = n;
    words.push_back(text.substr(start, stop - start));
    start = text.find_first_not_of(separators, stop+1);
    }
}

void
splitFilenames (const std::string &text,
                std::vector<std::string> &words)
{
  const std::string::size_type n = text.length();
  bool quoted;
  std::string comma(",");
  std::string quote("\"");
  std::string::size_type start = text.find_first_not_of(comma);
  while (start < n)
    {
    quoted = false;
    std::string::size_type startq = text.find_first_of(quote, start);
    std::string::size_type stopq = text.find_first_of(quote, startq+1);
    std::string::size_type stop = text.find_first_of(comma, start);
    if (stop > n) stop = n;
    if (startq != std::string::npos && stopq != std::string::npos)
      {
      while (startq < stop && stop < stopq && stop != n)
         {
         quoted = true;
         stop = text.find_first_of(comma, stop+1);
         if (stop > n) stop = n;
         }
      }
    if (!quoted)
      {
      words.push_back(text.substr(start, stop - start));
      }
    else
      {
      words.push_back(text.substr(start+1, stop - start-2));
      }
    start = text.find_first_not_of(comma, stop+1);
    }
}

char *GetXMLModuleDescription()
{
   return XMLModuleDescription;
}

#define GENERATE_LOGO
#define GENERATE_XML \
  if (argc >= 2 && (strcmp(argv[1],"--xml") == 0)) \
    { \
    std::cout << GetXMLModuleDescription(); \
    return EXIT_SUCCESS; \
    }
#define GENERATE_TCLAP \
    double radiusValue = 1.0; \
    std::string lowerClipValuesTemp = "-1224,1024"; \
    std::vector<int> lowerClipValues; \
    std::string upperClipValuesTemp = "1024,1024"; \
    std::vector<int> upperClipValues; \
    std::string ctFileName = "q"; \
    std::string outputFileName = "q"; \
    std::string ctDir = "q"; \
    bool echoSwitch = false; \
    bool xmlSwitch = false; \
    std::string processInformationAddressString = "0"; \
    std::string returnParameterFile; \
    std::string fullDescription("Description: "); \
    fullDescription += "Median Filter of a CT volume"; \
    if (!std::string("Applied Chest Imaging Laboratory, Brigham and women's hospital").empty()) \
      { \
      fullDescription += "\nAuthor(s): Applied Chest Imaging Laboratory, Brigham and women's hospital"; \
      } \
    if (!std::string("This work was partially funded ...").empty()) \
      { \
      fullDescription += "\nAcknowledgements: This work was partially funded ..."; \
      } \
    TCLAP::CmdLine commandLine (fullDescription, \
       ' ', \
      "0.0.1" ); \
 \
      std::ostringstream msg; \
    msg.str("");msg << "Median filter radius (default: " << radiusValue << ")"; \
    TCLAP::ValueArg<double > radiusValueArg("r", "Radius", msg.str(), 0, radiusValue, "double", commandLine); \
 \
    msg.str("");msg << "Lower clip value applied to input image before filtering. This flag should be followed by two values: the first value is the clip value and the second value is the replacement value (i.e., everything below the clip value will be assigned the replacement value) (default: " << lowerClipValuesTemp << ")"; \
    TCLAP::ValueArg<std::string > lowerClipValuesArg("l", "lowerClipValue", msg.str(), 0, lowerClipValuesTemp, "std::vector<int>", commandLine); \
 \
    msg.str("");msg << "Upper clip value applied to input image before filtering. This flag should be followed by two values: the first value is the clip value and the second value is the replacement value (i.e., everything below the clip value will be assigned the replacement value) (default: " << upperClipValuesTemp << ")"; \
    TCLAP::ValueArg<std::string > upperClipValuesArg("u", "upperClipValue", msg.str(), 0, upperClipValuesTemp, "std::vector<int>", commandLine); \
 \
    msg.str("");msg << "Input CT file name (default: " << ctFileName << ")"; \
    TCLAP::ValueArg<std::string > ctFileNameArg("i", "inputFile", msg.str(), 0, ctFileName, "std::string", commandLine); \
 \
    msg.str("");msg << "Output CT file name (default: " << outputFileName << ")"; \
    TCLAP::ValueArg<std::string > outputFileNameArg("o", "outputFile", msg.str(), 0, outputFileName, "std::string", commandLine); \
 \
    msg.str("");msg << "Directory image series (default: " << ctDir << ")"; \
    TCLAP::ValueArg<std::string > ctDirArg("d", "CTDirectory", msg.str(), 0, ctDir, "std::string", commandLine); \
 \
    msg.str("");msg << "Echo the command line arguments (default: " << echoSwitch << ")"; \
    TCLAP::SwitchArg echoSwitchArg("", "echo", msg.str(), commandLine, echoSwitch); \
 \
    msg.str("");msg << "Produce xml description of command line arguments (default: " << xmlSwitch << ")"; \
    TCLAP::SwitchArg xmlSwitchArg("", "xml", msg.str(), commandLine, xmlSwitch); \
 \
    msg.str("");msg << "Address of a structure to store process information (progress, abort, etc.). (default: " << processInformationAddressString << ")"; \
    TCLAP::ValueArg<std::string > processInformationAddressStringArg("", "processinformationaddress", msg.str(), 0, processInformationAddressString, "std::string", commandLine); \
 \
    msg.str("");msg << "Filename in which to write simple return parameters (int, float, int-vector, etc.) as opposed to bulk return parameters (image, geometry, transform, measurement, table).";    TCLAP::ValueArg<std::string > returnParameterFileArg("", "returnparameterfile", msg.str(), 0, returnParameterFile, "std::string", commandLine); \
 \
try \
  { \
    /* Build a map of flag aliases to the true flag */ \
    std::map<std::string,std::string> flagAliasMap; \
    std::map<std::string,std::string> deprecatedFlagAliasMap; \
    std::map<std::string,std::string> longFlagAliasMap; \
    std::map<std::string,std::string> deprecatedLongFlagAliasMap; \
    /* Remap flag aliases to the true flag */ \
    std::vector<std::string> targs; \
    std::map<std::string,std::string>::iterator ait; \
    std::map<std::string,std::string>::iterator dait; \
    size_t ac; \
    for (ac=0; ac < static_cast<size_t>(argc); ++ac)  \
       {  \
       if (strlen(argv[ac]) == 2 && argv[ac][0]=='-') \
         { \
         /* short flag case */ \
         std::string tflag(argv[ac], 1, strlen(argv[ac])-1); \
         ait = flagAliasMap.find(tflag); \
         dait = deprecatedFlagAliasMap.find(tflag); \
         if (ait != flagAliasMap.end() || dait != deprecatedFlagAliasMap.end()) \
           { \
           if (ait != flagAliasMap.end()) \
             { \
             /* remap the flag */ \
             targs.push_back("-" + (*ait).second); \
             } \
           else if (dait != deprecatedFlagAliasMap.end()) \
             { \
             std::cout << "Flag \"" << argv[ac] << "\" is deprecated. Please use flag \"-" << (*dait).second << "\" instead. " << std::endl; \
             /* remap the flag */ \
             targs.push_back("-" + (*dait).second); \
             } \
           } \
         else \
           { \
           targs.push_back(argv[ac]); \
           } \
         } \
       else if (strlen(argv[ac]) > 2 && argv[ac][0]=='-' && argv[ac][1]=='-') \
         { \
         /* long flag case */ \
         std::string tflag(argv[ac], 2, strlen(argv[ac])-2); \
         ait = longFlagAliasMap.find(tflag); \
         dait = deprecatedLongFlagAliasMap.find(tflag); \
         if (ait != longFlagAliasMap.end() || dait != deprecatedLongFlagAliasMap.end()) \
           { \
           if (ait != longFlagAliasMap.end()) \
             { \
             /* remap the flag */ \
             targs.push_back("--" + (*ait).second); \
             } \
           else if (dait != deprecatedLongFlagAliasMap.end()) \
             { \
             std::cout << "Long flag \"" << argv[ac] << "\" is deprecated. Please use long flag \"--" << (*dait).second << "\" instead. " << std::endl; \
             /* remap the flag */ \
             targs.push_back("--" + (*dait).second); \
             } \
           } \
         else \
           { \
           targs.push_back(argv[ac]); \
           } \
         } \
       else if (strlen(argv[ac]) > 2 && argv[ac][0]=='-' && argv[ac][1]!='-') \
         { \
         /* short flag case where multiple flags are given at once ala */ \
         /* "ls -ltr" */ \
         std::string tflag(argv[ac], 1, strlen(argv[ac])-1); \
         std::string rflag("-"); \
         for (std::string::size_type fi=0; fi < tflag.size(); ++fi) \
           { \
           std::string tf(tflag, fi, 1); \
           ait = flagAliasMap.find(tf); \
           dait = deprecatedFlagAliasMap.find(tf); \
           if (ait != flagAliasMap.end() || dait != deprecatedFlagAliasMap.end()) \
             { \
             if (ait != flagAliasMap.end()) \
               { \
               /* remap the flag */ \
               rflag += (*ait).second; \
               } \
             else if (dait != deprecatedFlagAliasMap.end()) \
               { \
               std::cout << "Flag \"-" << tf << "\" is deprecated. Please use flag \"-" << (*dait).second << "\" instead. " << std::endl; \
               /* remap the flag */ \
               rflag += (*dait).second; \
               } \
             } \
           else \
             { \
             rflag += tf; \
             } \
           } \
         targs.push_back(rflag); \
         } \
       else \
         { \
         /* skip the argument without remapping (this is the case for any */ \
         /* arguments for flags */ \
         targs.push_back(argv[ac]); \
         } \
       } \
 \
   /* Remap args to a structure that CmdLine::parse() can understand*/ \
   std::vector<char*> vargs; \
   for (ac = 0; ac < targs.size(); ++ac) \
     {  \
     vargs.push_back(const_cast<char *>(targs[ac].c_str())); \
     } \
    commandLine.parse ( vargs.size(), (char**) &(vargs[0]) ); \
    radiusValue = radiusValueArg.getValue(); \
    lowerClipValuesTemp = lowerClipValuesArg.getValue(); \
    upperClipValuesTemp = upperClipValuesArg.getValue(); \
    ctFileName = ctFileNameArg.getValue(); \
    outputFileName = outputFileNameArg.getValue(); \
    ctDir = ctDirArg.getValue(); \
    echoSwitch = echoSwitchArg.getValue(); \
    xmlSwitch = xmlSwitchArg.getValue(); \
    processInformationAddressString = processInformationAddressStringArg.getValue(); \
    returnParameterFile = returnParameterFileArg.getValue(); \
      { /* Assignment for lowerClipValues */ \
      std::vector<std::string> words; \
      std::string sep(","); \
      splitString(lowerClipValuesTemp, sep, words); \
      for (unsigned int _j = 0; _j < words.size(); _j++) \
        { \
        lowerClipValues.push_back(atoi(words[_j].c_str())); \
        } \
      } \
      { /* Assignment for upperClipValues */ \
      std::vector<std::string> words; \
      std::string sep(","); \
      splitString(upperClipValuesTemp, sep, words); \
      for (unsigned int _j = 0; _j < words.size(); _j++) \
        { \
        upperClipValues.push_back(atoi(words[_j].c_str())); \
        } \
      } \
  } \
catch ( TCLAP::ArgException e ) \
  { \
  std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; \
  return ( EXIT_FAILURE ); \
  }
#define GENERATE_ECHOARGS \
if (echoSwitch) \
{ \
std::cout << "Command Line Arguments" << std::endl; \
std::cout << "    radiusValue: " << radiusValue << std::endl; \
std::cout << "    lowerClipValues: "; \
for (unsigned int _i =0; _i < lowerClipValues.size(); _i++) \
{ \
std::cout << lowerClipValues[_i] << ", "; \
} \
std::cout <<std::endl; \
std::cout << "    upperClipValues: "; \
for (unsigned int _i =0; _i < upperClipValues.size(); _i++) \
{ \
std::cout << upperClipValues[_i] << ", "; \
} \
std::cout <<std::endl; \
std::cout << "    ctFileName: " << ctFileName << std::endl; \
std::cout << "    outputFileName: " << outputFileName << std::endl; \
std::cout << "    ctDir: " << ctDir << std::endl; \
std::cout << "    echoSwitch: " << echoSwitch << std::endl; \
std::cout << "    xmlSwitch: " << xmlSwitch << std::endl; \
std::cout << "    processInformationAddressString: " << processInformationAddressString << std::endl; \
std::cout << "    returnParameterFile: " << returnParameterFile << std::endl; \
}
#define GENERATE_ProcessInformationAddressDecoding \
ModuleProcessInformation *CLPProcessInformation = 0; \
if (processInformationAddressString != "") \
{ \
sscanf(processInformationAddressString.c_str(), "%p", &CLPProcessInformation); \
}
#define PARSE_ARGS GENERATE_LOGO;GENERATE_XML;GENERATE_TCLAP;GENERATE_ECHOARGS;GENERATE_ProcessInformationAddressDecoding;