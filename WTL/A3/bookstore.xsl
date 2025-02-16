<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">
        <html>
            <body>
                <h2>Bookstore Data</h2>
                <table border="1">
                    <tr bgcolor="#9acd32">
                        <th>Book Name</th>
                        <th>Buyer Name</th>
                        <th>Issue Date</th>
                        <th>Price</th>
                        <th>Author Name</th>
                    </tr>
                    <xsl:for-each select="bookstore/book">
                        <tr>
                            <td><xsl:value-of select="bookname"/></td>
                            <td><xsl:value-of select="buyername"/></td>
                            <td><xsl:value-of select="issuedate"/></td>
                            <td><xsl:value-of select="price"/></td>
                            <td><xsl:value-of select="authorname"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

</xsl:stylesheet>
