<?xml version='1.0'?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
                version='1.0'
                xmlns="http://www.w3.org/TR/xhtml1/transitional"
                exclude-result-prefixes="#default">


<xsl:include href="/home/ezust/workspace/slackerdoc/docbook-xsl/html/onechunk.xsl"/>

<xsl:include href="common.xsl" />
<!-- We do not want a toc generated for the set -->

<xsl:template match="programlisting[@role]" mode="class.value">
  <xsl:value-of select="@role"/>
</xsl:template>

<xsl:template match="example">
    <xsl:variable name="param.placement"
    select="substring-after(normalize-space($formal.title.placement),
    concat(local-name(.), ' '))"/>

  <xsl:variable name="placement">
    <xsl:choose>
      <xsl:when test="contains($param.placement, ' ')">
        <xsl:value-of select="substring-before($param.placement, ' ')"/>
      </xsl:when>
      <xsl:when test="$param.placement = ''">before</xsl:when>
      <xsl:otherwise>
        <xsl:value-of select="$param.placement"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:variable>
  <div class="{@role}">
  <xsl:call-template name="formal.object">
    <xsl:with-param name="placement" select="$placement"/>
    <xsl:with-param name="class" select="local-name(.)"/>
  </xsl:call-template>
  </div>
    <xsl:choose> <xsl:when test="@href">
      <p class="hyperlink"><a href="{@href}">
      <img src="icons/link.jpg" height="30" width="30"
      alt="(link)"/></a></p>
    </xsl:when> </xsl:choose>

</xsl:template>




<xsl:param name="generate.toc">
appendix  toc,title
article/appendix  nop
article   toc,title
book      toc,title,figure,table,example,equation
chapter   toc,title
part      toc,title
preface   toc,title
qandadiv  toc
qandaset  toc
reference toc,title
sect1     toc
sect2     toc
sect3     toc
sect4     toc
sect5     toc
section   toc
set       nop
</xsl:param>

<xsl:param name="table.borders.with.css">1</xsl:param>
<xsl:param name="body.font.family">Verdana</xsl:param>

<xsl:template name="admon.graphic">
  <xsl:param name="node" select="."/>
  <xsl:value-of select="$admon.graphics.path"/>
  <xsl:choose>
    <xsl:when test="local-name($node)='note'">note</xsl:when>
    <xsl:when test="local-name($node)='warning'">warning</xsl:when>
    <xsl:when test="local-name($node)='caution'">caution</xsl:when>
    <xsl:when test="local-name($node)='tip'">tip</xsl:when>
    <xsl:when test="local-name($node)='important'">important</xsl:when>
    <xsl:when test="local-name($node)='question'">question</xsl:when>
    <xsl:otherwise>note</xsl:otherwise>
  </xsl:choose>
  <xsl:value-of select="$admon.graphics.extension"/>
</xsl:template>


<xsl:template match="question">
  <xsl:choose>
    <xsl:when test="$admon.graphics != 0">
      <xsl:variable name="admon.type"> Question </xsl:variable>
    </xsl:when>
    <xsl:otherwise>
    <xsl:call-template name="nongraphical.admonition" />
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template match="parabook">
  <div class="parabook">
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="slides">
   <div class="slides">
      <xsl:apply-templates />
   </div>
</xsl:template>



<xsl:template match="bridgehead">
   <div class="cent">
   <h3>
       <xsl:apply-templates />
   </h3>
  </div>
</xsl:template>

<!-- By default, we ignore all stuff in bookonly tags -->

<xsl:template match="textbook">
  <div class="textbook">
    <xsl:apply-templates />
  </div>
</xsl:template>

<xsl:template match="remark">
  <div class="remark">
    <xsl:choose>
    <xsl:when test="@role[.='todo']">
      <p><b> Todo Items: </b></p>
    </xsl:when>
    </xsl:choose>
    <xsl:apply-templates />
   </div>
</xsl:template>

<xsl:template match="screenshot">
  <div class="screenshot">
<!--   <b> Program Output: </b> -->
    <xsl:apply-templates />
 </div>
</xsl:template>

<xsl:param name="chunker.output.encoding">utf-8</xsl:param>
<xsl:param name="chunk.section.depth" select="5"/>
<xsl:param name="chunk.section.depth" select="5"/>
<xsl:param name="chunk.first.sections" select="1"/>
<xsl:param name="toc.section.depth">3</xsl:param>
<xsl:param name="use.id.as.filename">1</xsl:param>
<xsl:param name="admon.graphics" select="1" />
<xsl:param name="admon.graphics.path">icons/</xsl:param>
<xsl:param name="callout.graphics.path">icons/callouts/</xsl:param>
<xsl:param name="admon.graphics.extension">.png</xsl:param>
<xsl:param name="navig.graphics" select="1" />
<xsl:param name="navig.graphics.path">icons/</xsl:param>
<xsl:param name="navig.graphics.extension">.png</xsl:param>
<xsl:param name="ignore.image.scaling" select="'1'"/>
<xsl:param name="callout.graphics.number.limit" select="'20'"/>
<!--
<xsl:param name="use.extensions" select="'1'"></xsl:param>
<xsl:param name="linenumbering.extension" select="'1'"></xsl:param>
<xsl:param name="linenumbering.everyNth" select="'1'"></xsl:param>
<xsl:param name="textinsert.extension" select="'1'"></xsl:param>
-->

<xsl:template match="classname">
    <span class="classname">
   <xsl:choose>
     <xsl:when test="@url">
        <a href="{@url}"><tt><xsl:value-of select="." /></tt></a>
     </xsl:when>
     <xsl:otherwise>
       <xsl:value-of select="." />
     </xsl:otherwise>
   </xsl:choose>
    </span>
</xsl:template>

<xsl:template match="emphasis">
  <xsl:choose>
    <xsl:when test="@role[.='strong']">
      <b><xsl:apply-templates/></b>
    </xsl:when>
    <xsl:when test="@role[.='bold']">
      <b><xsl:apply-templates/></b>
    </xsl:when>

    <xsl:otherwise>
      <i><xsl:apply-templates/></i>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>


<xsl:template match="command">
  <span class="command">
  <tt><xsl:apply-templates/></tt>
  </span>
</xsl:template>


<xsl:template name="user.header.content">
<script src="solutions.js" />
</xsl:template>

<xsl:template name="user.footer.content">
<table class="footer" width="100%">
<tr>
<td class="gendate"> Generated: July 25 2011 </td>
<td class="copyright"> &#x00A9; 2011 Paul Ezust and Alan Ezust. </td>
</tr>
</table>
 </xsl:template>


</xsl:stylesheet>
