require "application_system_test_case"

class IssueAreasTest < ApplicationSystemTestCase
  setup do
    @issue_area = issue_areas(:one)
  end

  test "visiting the index" do
    visit issue_areas_url
    assert_selector "h1", text: "Issue Areas"
  end

  test "creating a Issue area" do
    visit issue_areas_url
    click_on "New Issue Area"

    fill_in "Name", with: @issue_area.name
    click_on "Create Issue area"

    assert_text "Issue area was successfully created"
    click_on "Back"
  end

  test "updating a Issue area" do
    visit issue_areas_url
    click_on "Edit", match: :first

    fill_in "Name", with: @issue_area.name
    click_on "Update Issue area"

    assert_text "Issue area was successfully updated"
    click_on "Back"
  end

  test "destroying a Issue area" do
    visit issue_areas_url
    page.accept_confirm do
      click_on "Destroy", match: :first
    end

    assert_text "Issue area was successfully destroyed"
  end
end
