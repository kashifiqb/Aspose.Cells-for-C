/* Abstruct class header files*/
#include "publish\License.h"
#include "publish\CellsException.h"
#include "publish\Factory.h" 
#include "publish\IAboveAverage.h"
#include "publish\IArcShape.h" 
#include "publish\IArea.h" 
#include "publish\IAutoFilter.h"
#include "publish\IAutoFitterOptions.h"
#include "publish\IAxis.h"
#include "publish\IBevel.h"
#include "publish\IBorder.h"
#include "publish\IBorderCollection.h"
#include "publish\IBuiltInDocumentPropertyCollection.h"
#include "publish\IButton.h"
#include "publish\ICalculationOptions.h"
#include "publish\ICell.h"
#include "publish\ICellArea.h"
#include "publish\ICells.h"
#include "publish\ICellsColor.h"
#include "publish\ICellsHelper.h"
#include "publish\IChart.h"
#include "publish\IChartArea.h"   
#include "publish\IChartCollection.h"
#include "publish\IChartDataTable.h"
#include "publish\IChartPoint.h"
#include "publish\IChartPointCollection.h"
#include "publish\IChartShape.h"
#include "publish\ICheckBox.h"
#include "publish\ICheckBoxCollection.h"
#include "publish\IColorScale.h"
#include "publish\IColumn.h"
#include "publish\IColumnCollection.h"
#include "publish\IComboBox.h"
#include "publish\IComment.h"
#include "publish\ICommentCollection.h"
#include "publish\ICommentShape.h"
#include "publish\IConditionalFormattingCollection.h"
#include "publish\IConditionalFormattingIcon.h"
#include "publish\IConditionalFormattingIconCollection.h"
#include "publish\IConditionalFormattingResult.h"
#include "publish\IConditionalFormattingValue.h"
#include "publish\IConditionalFormattingValueCollection.h"
#include "publish\IContentTypeProperty.h"
#include "publish\IContentTypePropertyCollection.h"
#include "publish\ICopyOptions.h"
#include "publish\ICustomDocumentPropertyCollection.h"
#include "publish\ICustomFunction.h"
#include "publish\ICustomProperty.h"
#include "publish\ICustomPropertyCollection.h"
#include "publish\IDataBar.h"
#include "publish\IDataBarBorder.h"
#include "publish\IDataLabels.h"
#include "publish\IDataSorter.h"
#include "publish\IDigitalSignature.h"
#include "publish\IDigitalSignatureCollection.h"
#include "publish\IDisplayUnitLabel.h"
#include "publish\IDocumentProperty.h"
#include "publish\IDocumentPropertyCollection.h"
#include "publish\IErrorBar.h" 
#include "publish\IErrorCheckOption.h"
#include "publish\IErrorCheckOptionCollection.h"
#include "publish\IExternalLink.h"
#include "publish\IExternalLinkCollection.h"
#include "publish\IFileFormatInfo.h"
#include "publish\IFileFormatUtil.h"
#include "publish\IFillFormat.h"
#include "publish\IFindOptions.h"
#include "publish\IFloor.h"
#include "publish\IFont.h"
#include "publish\IFontSetting.h"
#include "publish\IFormat3D.h"
#include "publish\IFormatCondition.h"
#include "publish\IFormatConditionCollection.h"
#include "publish\IGradientFill.h"
#include "publish\IGradientStopCollection.h"
#include "publish\IGroupBox.h"
#include "publish\IGroupShape.h"
#include "publish\IHeaderFooterCommand.h"
#include "publish\IHorizontalPageBreak.h"
#include "publish\IHorizontalPageBreakCollection.h"
#include "publish\IHtmlSaveOptions.h"
#include "publish\IHyperlink.h"
#include "publish\IHyperlinkCollection.h"
#include "publish\IIconSet.h"
#include "publish\IImageOrPrintOptions.h"
#include "publish\ILabel.h"
#include "publish\ILegend.h"
#include "publish\ILegendEntry.h"
#include "publish\ILegendEntryCollection.h"
#include "publish\ILightCellsDataHandler.h"
#include "publish\ILine.h"   
#include "publish\ILineShape.h"
#include "publish\IListBox.h"
#include "publish\IListColumn.h"
#include "publish\IListColumnCollection.h"
#include "publish\IListObject.h"
#include "publish\IListObjectCollection.h"
#include "publish\ILoadDataOption.h"
#include "publish\ILoadOptions.h"
#include "publish\IMarker.h"
#include "publish\IMetadataOptions.h"
#include "publish\IMsoFillFormat.h"
#include "publish\IMsoFormatPicture.h"
#include "publish\IMsoLineFormat.h"
#include "publish\IMsoTextFrame.h"
#include "publish\IName.h"
#include "publish\INameCollection.h"
#include "publish\INegativeBarFormat.h"
#include "publish\IOleObject.h"
#include "publish\IOleObjectCollection.h"
#include "publish\IOoxmlSaveOptions.h"
#include "publish\IOutline.h"
#include "publish\IPageSetup.h"
#include "publish\IPaneCollection.h"
#include "publish\IPasteOptions.h"
#include "publish\IPatternFill.h"
#include "publish\IPdfBookmarkEntry.h"
#include "publish\IPdfSaveOptions.h"
#include "publish\IPicture.h"
#include "publish\IPictureCollection.h"
#include "publish\IPivotField.h"
#include "publish\IPivotFieldCollection.h"
#include "publish\IPivotFilter.h"
#include "publish\IPivotFilterCollection.h"
#include "publish\IPivotFormatCondition.h"
#include "publish\IPivotFormatConditionCollection.h"
#include "publish\IPivotItem.h"
#include "publish\IPivotItemCollection.h"
#include "publish\IPivotOptions.h"
#include "publish\IPivotPageFields.h"
#include "publish\IPivotTable.h"
#include "publish\IPivotTableCollection.h"
#include "publish\IPlotArea.h"
#include "publish\IProtectedRange.h"
#include "publish\IProtectedRangeCollection.h"
#include "publish\IProtection.h"
#include "publish\IRadioButton.h"
#include "publish\IRange.h"
#include "publish\IRangeCollection.h"
#include "publish\IRectangleShape.h"
#include "publish\IReferredArea.h"
#include "publish\IReferredAreaCollection.h"
#include "publish\IReplaceOptions.h"
#include "publish\IRow.h"
#include "publish\IRowCollection.h"
#include "publish\ISaveOptions.h"
#include "publish\IScenario.h"
#include "publish\IScenarioCollection.h"
#include "publish\IScenarioInputCell.h"
#include "publish\IScenarioInputCellCollection.h"
#include "publish\IScrollBar.h"
#include "publish\ISeries.h"
#include "publish\ISeriesCollection.h"
#include "publish\IShape.h" 
#include "publish\IShapeCollection.h"
#include "publish\IShapePath.h" 
#include "publish\IShapePathCollection.h" 
#include "publish\IShapePropertyCollection.h"
#include "publish\IShapeSegmentPath.h"
#include "publish\IShapeSegmentPathCollection.h"
#include "publish\ISheetRender.h"
#include "publish\ISparkline.h"
#include "publish\ISparklineCollection.h"
#include "publish\ISparklineGroup.h"
#include "publish\ISparklineGroupCollection.h"
#include "publish\ISpreadsheetML2003SaveOptions.h"
#include "publish\ISolidFill.h"
#include "publish\IStyle.h"
#include "publish\IStyleCollection.h"
#include "publish\IStyleFlag.h"
#include "publish\ISxRng.h"
#include "publish\ITextBox.h"
#include "publish\ITextBoxCollection.h"
#include "publish\ITextEffectFormat.h"
#include "publish\ITextureFill.h"
#include "publish\IThemeColor.h"
#include "publish\ITickLabels.h"
#include "publish\ITitle.h"
#include "publish\ITop10.h"
#include "publish\ITrendline.h"
#include "publish\ITrendlineCollection.h"   
#include "publish\IValidation.h"
#include "publish\IValidationCollection.h"
#include "publish\IVbaProject.h"
#include "publish\IVbaProjectReferenceCollection.h"
#include "publish\IVbaModule.h"
#include "publish\IVbaModuleCollection.h"
#include "publish\IVerticalPageBreak.h"
#include "publish\IVerticalPageBreakCollection.h"
#include "publish\IWalls.h"
#include "publish\IWorkbook.h"
#include "publish\IWorkbookDesigner.h"
#include "publish\IWorkbookMetadata.h"
#include "publish\IWorkbookSettings.h"
#include "publish\IWorksheet.h"
#include "publish\IWorksheetCollection.h"
#include "publish\IWriteProtection.h"
/*Enum type header files*/
#include "publish\AutoShapeType.h"  
#include "publish\BackgroundMode.h"  
#include "publish\BackgroundType.h"
#include "publish\Bar3DShapeType.h"
#include "publish\BevelPresetType.h"
#include "publish\BorderType.h"
#include "publish\BubbleSizeRepresents.h"
#include "publish\BuiltinStyleType.h"
#include "publish\CalcModeType.h"
#include "publish\CalculationPrecisionStrategy.h"
#include "publish\CategoryType.h"  
#include "publish\CellBorderType.h"
#include "publish\CellValueFormatStrategy.h"
#include "publish\CellValueType.h"
#include "publish\ChartMarkerType.h"  
#include "publish\ChartSplitType.h"
#include "publish\ChartType.h"
#include "publish\ColorType.h"
#include "publish\ConsolidationFunction.h"
#include "publish\CountryCode.h"
#include "publish\CrossType.h"  
#include "publish\DataBarAxisPosition.h"
#include "publish\DataBarBorderType.h"
#include "publish\DataBarFillType.h"
#include "publish\DataBarNegativeColorType.h"
#include "publish\DataLablesSeparatorType.h"
#include "publish\DateTimeGroupingType.h"
#include "publish\DirectoryType.h"
#include "publish\DisplayDrawingObjects.h"
#include "publish\DisplayUnitType.h"  
#include "publish\DynamicFilterType.h"
#include "publish\ErrorBarType.h"  
#include "publish\ErrorBarDisplayType.h"  
#include "publish\ErrorCheckType.h"
#include "publish\ExceptionType.h"
#include "publish\FileFormatType.h"
#include "publish\FillPattern.h"  
#include "publish\FillPictureType.h"  
#include "publish\FillType.h"
#include "publish\FilterOperatorType.h"
#include "publish\FontUnderlineType.h"
#include "publish\FormatConditionType.h"
#include "publish\FormatConditionValueType.h"
#include "publish\FormatSetType.h"  
#include "publish\FormattingType.h"  
#include "publish\GradientColorType.h"  
#include "publish\GradientPresetType.h"  
#include "publish\GradientStyleType.h"
#include "publish\GradientStyleType.h"  
#include "publish\HtmlCrossType.h"  
#include "publish\HeaderFooterCommandType.h" 
#include "publish\IPageSavingCallback.h"
#include "publish\IconSetType.h"
#include "publish\LabelPositionType.h"
#include "publish\LegendPositionType.h"
#include "publish\LightRigType.h"
#include "publish\LineType.h"  
#include "publish\LoadDataFilterOptions.h"
#include "publish\LoadFormat.h"
#include "publish\LookAtType.h"
#include "publish\LookInType.h"
#include "publish\MemorySetting.h"
#include "publish\MetadataType.h"
#include "publish\MsoArrowheadLength.h"
#include "publish\MsoArrowheadStyle.h"  
#include "publish\MsoDrawingType.h" 
#include "publish\MsoLineStyle.h" 
#include "publish\MsoLineDashStyle.h" 
#include "publish\MsoPresetTextEffect.h"
#include "publish\NumberCategoryType.h"
#include "publish\OperatorType.h"
#include "publish\PageOrientationType.h"
#include "Publish\PageSavingArgs.h"
#include "Publish\PageStartSavingArgs.h"
#include "Publish\PageEndSavingArgs.h"
#include "publish\PaperSizeType.h"
#include "publish\ParameterType.h"
#include "publish\PasteType.h"
#include "publish\PdfCompliance.h"
#include "publish\PivotConditionFormatRuleType.h" 
#include "publish\PivotConditionFormatScopeType.h" 
#include "publish\PivotFieldDataDisplayFormat.h" 
#include "publish\PivotFieldSubtotalType.h"  
#include "publish\PivotFieldType.h"
#include "publish\PivotFilterType.h"  
#include "publish\PivotGroupByType.h"
#include "publish\PivotItemPosition.h" 
#include "publish\PivotMissingItemLimitType.h"
#include "publish\PivotTableAutoFormatType.h"
#include "publish\PivotTableStyleType.h"
#include "publish\PlacementType.h"
#include "publish\PlotEmptyCellsType.h"
#include "publish\PresetMaterialType.h"
#include "publish\PrintCommentsType.h"
#include "publish\PrintErrorsType.h"
#include "publish\PrintOrderType.h"
#include "publish\PropertyType.h"
#include "publish\ProtectionType.h"
#include "publish\RectangleAlignmentType.h"
#include "publish\SaveFormat.h"
#include "publish\SelectionType.h"
#include "publish\SheetType.h"
#include "publish\ShiftType.h"
#include "publish\SortOrder.h"
#include "publish\SparklineType.h"
#include "publish\StyleModifyFlag.h"
#include "publish\TableDataSourceType.h"
#include "publish\TableStyleType.h"
#include "publish\TextAlignmentType.h"
#include "publish\TextCapsType.h"
#include "publish\TextDirectionType.h"
#include "publish\TextDirectionType.h"  
#include "publish\TextOrientationType.h"
#include "publish\TextOverflowType.h"
#include "publish\TextNodeType.h"
#include "publish\TextStrikeType.h"
#include "publish\TextureType.h"  
#include "publish\ThemeColorType.h"
#include "publish\TickMarkType.h"
#include "publish\TiffCompression.h"
#include "publish\TickLabelPositionType.h"
#include "publish\TimePeriodType.h"
#include "publish\TimeUnit.h"  
#include "publish\TotalsCalculation.h"
#include "publish\TrendlineType.h"
#include "publish\TxtLoadStyleStrategy.h"
#include "publish\TxtValueQuoteType.h"
#include "publish\UpdateLinksType.h"
#include "publish\ValidationAlertType.h"
#include "publish\ValidationType.h"
#include "publish\VbaModuleType.h"
#include "publish\ViewType.h"
#include "publish\VisibilityType.h"
#include "publish\WeightType.h"
/*System lib header files*/
#include "Aspose.Cells.Systems\ApplicationException.h"
#include "Aspose.Cells.Systems\ArgumentException.h"
#include "Aspose.Cells.Systems\ArgumentNullException.h"
#include "Aspose.Cells.Systems\ArgumentOutOfRangeException.h"
#include "Aspose.Cells.Systems\ArithmeticException.h"
#include "Aspose.Cells.Systems\Array.h"
#include "Aspose.Cells.Systems\Array1D.h"
#include "Aspose.Cells.Systems\Array2D.h"
#include "Aspose.Cells.Systems\ArrayHelper.h"
#include "Aspose.Cells.Systems\Base64FormattingOptions.h"
#include "Aspose.Cells.Systems\BaseNumber.h"
#include "Aspose.Cells.Systems\BitConverter.h"
#include "Aspose.Cells.Systems\Boolean.h"
#include "Aspose.Cells.Systems\BooleanHelper.h"
#include "Aspose.Cells.Systems\Boxing.h"
#include "Aspose.Cells.Systems\Byte.h"
#include "Aspose.Cells.Systems\ByteHelper.h"
#include "Aspose.Cells.Systems\Char.h"
#include "Aspose.Cells.Systems\CharHelper.h"
#include "Aspose.Cells.Systems\Collections\ArrayList.h"
#include "Aspose.Cells.Systems\Collections\ArrayListEnumeratorSimple.h"
#include "Aspose.Cells.Systems\Collections\CollectionBase.h"
#include "Aspose.Cells.Systems\Collections\Comparer.h"
#include "Aspose.Cells.Systems\Collections\DictionaryEntry.h"
#include "Aspose.Cells.Systems\Collections\HashCodeHelper.h"
#include "Aspose.Cells.Systems\Collections\HashHelpers.h"
#include "Aspose.Cells.Systems\Collections\Hashtable.h"
#include "Aspose.Cells.Systems\Collections\ICollection.h"
#include "Aspose.Cells.Systems\Collections\IComparer.h"
#include "Aspose.Cells.Systems\Collections\IDictionary.h"
#include "Aspose.Cells.Systems\Collections\IDictionaryEnumerator.h"
#include "Aspose.Cells.Systems\Collections\IEnumerable.h"
#include "Aspose.Cells.Systems\Collections\IEnumerator.h"
#include "Aspose.Cells.Systems\Collections\IEqualityComparer.h"
#include "Aspose.Cells.Systems\Collections\IList.h"
#include "Aspose.Cells.Systems\Collections\KeyValuePairs.h"
#include "Aspose.Cells.Systems\Collections\SortedList.h"
#include "Aspose.Cells.Systems\Collections\Sorter.h"
#include "Aspose.Cells.Systems\Collections\Specialized\CollectionsUtil.h"
#include "Aspose.Cells.Systems\Collections\Stack.h"
#include "Aspose.Cells.Systems\Collections\StackEnumerator.h"
#include "Aspose.Cells.Systems\Collections\SyncHashtable.h"
#include "Aspose.Cells.Systems\Collections\SyncStack.h"
#include "Aspose.Cells.Systems\Console.h"
#include "Aspose.Cells.Systems\Convert.h"
#include "Aspose.Cells.Systems\DateTime.h"
#include "Aspose.Cells.Systems\DateTimeKind.h"
#include "Aspose.Cells.Systems\DateTimeParse.h"
#include "Aspose.Cells.Systems\DateTimeResult.h"
#include "Aspose.Cells.Systems\DayOfWeek.h"
#include "Aspose.Cells.Systems\Decimal.h"
#include "Aspose.Cells.Systems\DecimalHelper.h"
#include "Aspose.Cells.Systems\Diagnostics\Debug.h"
#include "Aspose.Cells.Systems\Double.h"
#include "Aspose.Cells.Systems\DoubleHelper.h"
#include "Aspose.Cells.Systems\Drawing\Bitmap.h"
#include "Aspose.Cells.Systems\Drawing\Brush.h"
#include "Aspose.Cells.Systems\Drawing\Color.h"
#include "Aspose.Cells.Systems\Drawing\ColorTranslator.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\CombineMode.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\CompositingMode.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\CompositingQuality.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\DashCap.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\DashStyle.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\FillMode.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\GraphicsPath.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\GraphicsPathIterator.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\GraphicsState.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\HatchBrush.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\HatchStyle.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\InterpolationMode.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\LinearGradientBrush.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\LinearGradientMode.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\LineCap.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\LineJoin.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\Matrix.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\MatrixOrder.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\PathData.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\PathGradientBrush.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\PathPointType.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\PenType.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\SmoothingMode.h"
#include "Aspose.Cells.Systems\Drawing\Drawing2D\WrapMode.h"
#include "Aspose.Cells.Systems\Drawing\FontFamily.h"
#include "Aspose.Cells.Systems\Drawing\FontPal.h"
#include "Aspose.Cells.Systems\Drawing\FontStyle.h"
#include "Aspose.Cells.Systems\Drawing\Graphics.h"
#include "Aspose.Cells.Systems\Drawing\GraphicsUnit.h"
#include "Aspose.Cells.Systems\Drawing\Image.h"
#include "Aspose.Cells.Systems\Drawing\Imaging\EncoderParameter.h"
#include "Aspose.Cells.Systems\Drawing\Imaging\ImageCodecInfo.h"
#include "Aspose.Cells.Systems\Drawing\Imaging\ImageFlags.h"
#include "Aspose.Cells.Systems\Drawing\Imaging\ImageFormat.h"
#include "Aspose.Cells.Systems\Drawing\Imaging\Metafile.h"
#include "Aspose.Cells.Systems\Drawing\Imaging\PixelFormat.h"
#include "Aspose.Cells.Systems\Drawing\KnownColor.h"
#include "Aspose.Cells.Systems\Drawing\KnownColorTable.h"
#include "Aspose.Cells.Systems\Drawing\Pen.h"
#include "Aspose.Cells.Systems\Drawing\Point.h"
#include "Aspose.Cells.Systems\Drawing\PointF.h"
#include "Aspose.Cells.Systems\Drawing\Printing\PrinterSettings.h"
#include "Aspose.Cells.Systems\Drawing\Printing\PrintPageEventHandler.h"
#include "Aspose.Cells.Systems\Drawing\Printing\QueryPageSettingsEventHandler.h"
#include "Aspose.Cells.Systems\Drawing\Rectangle.h"
#include "Aspose.Cells.Systems\Drawing\RectangleF.h"
#include "Aspose.Cells.Systems\Drawing\Size.h"
#include "Aspose.Cells.Systems\Drawing\SizeF.h"
#include "Aspose.Cells.Systems\Drawing\SolidBrush.h"
#include "Aspose.Cells.Systems\Drawing\StringAlignment.h"
#include "Aspose.Cells.Systems\Drawing\StringFormat.h"
#include "Aspose.Cells.Systems\Drawing\StringFormatFlags.h"
#include "Aspose.Cells.Systems\Drawing\StringTrimming.h"
#include "Aspose.Cells.Systems\Drawing\SystemColors.h"
#include "Aspose.Cells.Systems\Drawing\TextureBrush.h"
#include "Aspose.Cells.Systems\Drawing\Text\TextRenderingHint.h"
#include "Aspose.Cells.Systems\Environment.h"
#include "Aspose.Cells.Systems\Exception.h"
#include "Aspose.Cells.Systems\FormatException.h"
#include "Aspose.Cells.Systems\GC.h"
#include "Aspose.Cells.Systems\Globalization\CalendarAlgorithmType.h"
#include "Aspose.Cells.Systems\Globalization\CalendarC.h"
#include "Aspose.Cells.Systems\Globalization\CalendarId.h"
#include "Aspose.Cells.Systems\Globalization\CalendarWeekRule.h"
#include "Aspose.Cells.Systems\Globalization\CompareOptions.h"
#include "Aspose.Cells.Systems\Globalization\CountryCodeC.h"
#include "Aspose.Cells.Systems\Globalization\CultureInfo.h"
#include "Aspose.Cells.Systems\Globalization\CultureNotFoundException.h"
#include "Aspose.Cells.Systems\Globalization\DateTimeFormatFlags.h"
#include "Aspose.Cells.Systems\Globalization\DateTimeFormatInfo.h"
#include "Aspose.Cells.Systems\Globalization\DateTimeStyles.h"
#include "Aspose.Cells.Systems\Globalization\DigitShapes.h"
#include "Aspose.Cells.Systems\Globalization\FORMATFLAGS.h"
#include "Aspose.Cells.Systems\Globalization\GregorianCalendarTypes.h"
#include "Aspose.Cells.Systems\Globalization\HebrewNumberParsingState.h"
#include "Aspose.Cells.Systems\Globalization\JapaneseCalendar.h"
#include "Aspose.Cells.Systems\Globalization\KoreanCalendar.h"
#include "Aspose.Cells.Systems\Globalization\LangCodeC.h"
#include "Aspose.Cells.Systems\Globalization\MonthNameStyles.h"
#include "Aspose.Cells.Systems\Globalization\NumberFormatInfo.h"
#include "Aspose.Cells.Systems\Globalization\NumberStyles.h"
#include "Aspose.Cells.Systems\Globalization\PalCultureInfoUtilC.h"
#include "Aspose.Cells.Systems\Globalization\RegionInfo.h"
#include "Aspose.Cells.Systems\Guid.h"
#include "Aspose.Cells.Systems\ICloneable.h"
#include "Aspose.Cells.Systems\IComparable.h"
#include "Aspose.Cells.Systems\IDisposable.h"
#include "Aspose.Cells.Systems\IFormatProvider.h"
#include "Aspose.Cells.Systems\IndexOutOfRangeException.h"
#include "Aspose.Cells.Systems\Int16.h"
#include "Aspose.Cells.Systems\Int16Helper.h"
#include "Aspose.Cells.Systems\Int32.h"
#include "Aspose.Cells.Systems\Int32Helper.h"
#include "Aspose.Cells.Systems\Int64.h"
#include "Aspose.Cells.Systems\Int64Helper.h"
#include "Aspose.Cells.Systems\IntegerPtr.h"
#include "Aspose.Cells.Systems\InvalidOperationException.h"
#include "Aspose.Cells.Systems\InvalidTimeZoneException.h"
#include "Aspose.Cells.Systems\IO\BinaryReader.h"
#include "Aspose.Cells.Systems\IO\BinaryWriter.h"
#include "Aspose.Cells.Systems\IO\Directory.h"
#include "Aspose.Cells.Systems\IO\DirectoryInfo.h"
#include "Aspose.Cells.Systems\IO\EndOfStreamException.h"
#include "Aspose.Cells.Systems\IO\File.h"
#include "Aspose.Cells.Systems\IO\FileAccess.h"
#include "Aspose.Cells.Systems\IO\FileInfo.h"
#include "Aspose.Cells.Systems\IO\FileMode.h"
#include "Aspose.Cells.Systems\IO\FileOptions.h"
#include "Aspose.Cells.Systems\IO\FileShare.h"
#include "Aspose.Cells.Systems\IO\FileStream.h"
#include "Aspose.Cells.Systems\IO\FileSystemInfo.h"
#include "Aspose.Cells.Systems\IO\IOException.h"
#include "Aspose.Cells.Systems\IO\MemoryStream.h"
#include "Aspose.Cells.Systems\IO\NullStream.h"
#include "Aspose.Cells.Systems\IO\NullStreamReader.h"
#include "Aspose.Cells.Systems\IO\Path.h"
#include "Aspose.Cells.Systems\IO\PathHelper.h"
#include "Aspose.Cells.Systems\IO\SearchOption.h"
#include "Aspose.Cells.Systems\IO\SeekOrigin.h"
#include "Aspose.Cells.Systems\IO\Stream.h"
#include "Aspose.Cells.Systems\IO\StreamReader.h"
#include "Aspose.Cells.Systems\IO\StreamWriter.h"
#include "Aspose.Cells.Systems\IO\StringWriter.h"
#include "Aspose.Cells.Systems\IO\TextReader.h"
#include "Aspose.Cells.Systems\IO\TextWriter.h"
#include "Aspose.Cells.Systems\IO\WStringWriter.h"
#include "Aspose.Cells.Systems\Math.h"
#include "Aspose.Cells.Systems\MidpointRounding.h"
#include "Aspose.Cells.Systems\NotImplementedException.h"
#include "Aspose.Cells.Systems\NotSupportedException.h"
#include "Aspose.Cells.Systems\NullReferenceException.h"
#include "Aspose.Cells.Systems\NumberC.h"
#include "Aspose.Cells.Systems\NumberFormatC.h"
#include "Aspose.Cells.Systems\Object.h"
#include "Aspose.Cells.Systems\ObjectDisposedException.h"
#include "Aspose.Cells.Systems\OutOfMemoryException.h"
#include "Aspose.Cells.Systems\OverflowException.h"
#include "Aspose.Cells.Systems\PalFormatterC.h"
#include "Aspose.Cells.Systems\ParseFailureKind.h"
#include "Aspose.Cells.Systems\ParseFlags.h"
#include "Aspose.Cells.Systems\PrimitiveToStringHelper.h"
#include "Aspose.Cells.Systems\Random.h"
#include "Aspose.Cells.Systems\RankException.h"
#include "Aspose.Cells.Systems\reference_counter.h"
#include "Aspose.Cells.Systems\Runtime\InteropServices\VarEnum.h"
#include "Aspose.Cells.Systems\SByte.h"
#include "Aspose.Cells.Systems\SByteHelper.h"
#include "Aspose.Cells.Systems\Security\Cryptography\CryptographicException.h"
#include "Aspose.Cells.Systems\Security\Cryptography\CryptographicUnexpectedOperationException.h"
#include "Aspose.Cells.Systems\Security\Cryptography\HashAlgorithm.h"
#include "Aspose.Cells.Systems\Security\Cryptography\ICryptoTransform.h"
#include "Aspose.Cells.Systems\Security\Cryptography\MD5.h"
#include "Aspose.Cells.Systems\Security\Cryptography\MD5CryptoServiceProvider.h"
#include "Aspose.Cells.Systems\SimpleDateFormatC.h"
#include "Aspose.Cells.Systems\Single.h"
#include "Aspose.Cells.Systems\SingleHelper.h"
#include "Aspose.Cells.Systems\String.h"
#include "Aspose.Cells.Systems\StringComparison.h"
#include "Aspose.Cells.Systems\StringHelperPal.h"
#include "Aspose.Cells.Systems\StringSplitOptions.h"
#include "Aspose.Cells.Systems\System.h"
#include "Aspose.Cells.Systems\Text\ASCIIEncoding.h"
#include "Aspose.Cells.Systems\Text\Decoder.h"
#include "Aspose.Cells.Systems\Text\DecoderNLS.h"
#include "Aspose.Cells.Systems\Text\Encoder.h"
#include "Aspose.Cells.Systems\Text\EncoderNLS.h"
#include "Aspose.Cells.Systems\Text\Encoding.h"
#include "Aspose.Cells.Systems\Text\ICUEncoding.h"
#include "Aspose.Cells.Systems\Text\PendingInfo.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\Group.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\GroupCollection.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\Match.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\MatchCollection.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\NamedMatcher.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\NamedMatchResult.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\NamedPattern.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\Regex.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\RegexHelper.h"
#include "Aspose.Cells.Systems\Text\RegularExpressions\RegexOptions.h"
#include "Aspose.Cells.Systems\Text\StringBuilder.h"
#include "Aspose.Cells.Systems\Text\UnicodeEncoding.h"
#include "Aspose.Cells.Systems\Text\UTF8Encoding.h"
#include "Aspose.Cells.Systems\Threading\Thread.h"
#include "Aspose.Cells.Systems\TimeoutException.h"
#include "Aspose.Cells.Systems\TimeSpan.h"
#include "Aspose.Cells.Systems\TimeZoneInfoOptions.h"
#include "Aspose.Cells.Systems\TokenType.h"
#include "Aspose.Cells.Systems\Type.h"
#include "Aspose.Cells.Systems\TypeCode.h"
#include "Aspose.Cells.Systems\TypeDefBString.h"
#include "Aspose.Cells.Systems\UInt16.h"
#include "Aspose.Cells.Systems\UInt16Helper.h"
#include "Aspose.Cells.Systems\UInt32.h"
#include "Aspose.Cells.Systems\UInt32Helper.h"
#include "Aspose.Cells.Systems\UInt64.h"
#include "Aspose.Cells.Systems\UInt64Helper.h"
#include "Aspose.Cells.Systems\Win32\Registry.h"
#include "Aspose.Cells.Systems\Win32\RegistryKey.h"
#include "Aspose.Cells.Systems\Zip\CompressionLevel.h"
#include "Aspose.Cells.Systems\Zip\CRC32.h"
#include "Aspose.Cells.Systems\Zip\CrcCalculatorStream.h"
#include "Aspose.Cells.Systems\Zip\Deflate.h"
#include "Aspose.Cells.Systems\Zip\DeflateStream.h"
#include "Aspose.Cells.Systems\Zip\Inflate.h"
#include "Aspose.Cells.Systems\Zip\InfTree.h"
#include "Aspose.Cells.Systems\Zip\OffsetStream.h"
#include "Aspose.Cells.Systems\Zip\SharedUtilities.h"
#include "Aspose.Cells.Systems\Zip\Tree.h"
#include "Aspose.Cells.Systems\Zip\Zip64Option.h"
#include "Aspose.Cells.Systems\Zip\ZipContainer.h"
#include "Aspose.Cells.Systems\Zip\ZipEntry.h"
#include "Aspose.Cells.Systems\Zip\ZipException.h"
#include "Aspose.Cells.Systems\Zip\ZipFile.h"
#include "Aspose.Cells.Systems\Zip\ZipOptions.h"
#include "Aspose.Cells.Systems\Zip\ZipOutputStream.h"
#include "Aspose.Cells.Systems\Zip\Zlib.h"
#include "Aspose.Cells.Systems\Zip\ZlibBaseStream.h"
#include "Aspose.Cells.Systems\Zip\ZlibCodec.h"
/* Aspose::Cells is the topmost namespace for Cells */

using namespace Aspose::Cells;
using namespace Aspose::Cells::Systems;
using namespace Aspose::Cells::Drawing;
using namespace Aspose::Cells::Tables;
using namespace Aspose::Cells::Pivot;
using namespace Aspose::Cells::Properties;
using namespace Aspose::Cells::Metadata;
using namespace Aspose::Cells::Charts;
using namespace Aspose::Cells::Vba;
using namespace Aspose::Cells::Rendering;