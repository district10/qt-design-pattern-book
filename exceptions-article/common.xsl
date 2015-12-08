<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">
<!-- This file contains common definitions for the print and HTML versions
     of oopdocbook, based on docbook-xsl 1.69 -->

<!-- Make section numbering hierarchical -->     
<xsl:param name="section.autolabel" select="1"/>
<xsl:param name="xref.with.number.and.title" select="0"/>
<xsl:param name="section.label.includes.component.label" select="1"/>

<xsl:param name="local.l10n.xml" select="document('')"/> 
<l:i18n xmlns:l="http://docbook.sourceforge.net/xmlns/l10n/1.0"> 
  <l:l10n language="en">   
 <l:gentext key="sectioncalled" text=""/>    
<l:context name="xref">
   <l:template name="example" text="%n"/>
   <l:template name="abstract" text="%n"/>
   <l:template name="appendix" text="%n"/>
   <l:template name="informalfigure" text="%n"/>
   <l:template name="chapter" text="%n"/>
   <l:template name="section" text="%n"/>
   <l:template name="table" text="%n"/>
</l:context>
    
    <l:context name="xref-number-and-title">
        <l:template name="section" text="Section %n"/>
        <l:template name="table" text="Table %n"/>
        <l:template name="chapter" text="Chapter %n"/>
        <l:template name="example" text="Example %n"/>
        <l:template name="figure" text="Figure %n"/>
        <l:template name="informalfigure" text="Figure %n"/>
        <l:template name="appendix" text="Appendix %n"/>
    </l:context>
    
    <l:context name="xref-number">
        <l:template name="table" text="Table %n"/>
        <l:template name="section" text="Section %n"/>    
        <l:template name="chapter" text="Chapter %n"/>
        <l:template name="example" text="Example %n"/>
        <l:template name="figure" text="Figure %n"/>
        <l:template name="informalfigure" text="Figure %n"/>
        <l:template name="appendix" text="Appendix %n"/>
    </l:context> 
</l:l10n>
</l:i18n>

</xsl:stylesheet>
