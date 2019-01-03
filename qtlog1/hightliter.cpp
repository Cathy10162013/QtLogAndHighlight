#include "hightliter.h"

//! [0]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;


    //! [1]
        InfoFormat.setFontWeight(QFont::Bold);
        InfoFormat.setForeground(Qt::green);
        rule.pattern = QRegularExpression("INFO");
        rule.format = InfoFormat;
        highlightingRules.append(rule);

        //! [1]
            WarnFormat.setFontWeight(QFont::Bold);
            WarnFormat.setForeground(Qt::magenta);
            rule.pattern = QRegularExpression("WARN");
            rule.format = WarnFormat;
            highlightingRules.append(rule);

            //! [1]
                ErrorFormat.setFontWeight(QFont::Bold);
                ErrorFormat.setForeground(Qt::red);
                rule.pattern = QRegularExpression("ERROR");
                rule.format = ErrorFormat;
                highlightingRules.append(rule);
}
//! [6]

//! [7]
void Highlighter::highlightBlock(const QString &text)//应用高亮规则，也用于区块的高亮，比如多行注释
{
    foreach (const HighlightingRule &rule, highlightingRules) {//文本采用高亮规则
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
//! [11]
