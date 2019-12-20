require 'test_helper'

class IssueAreasControllerTest < ActionDispatch::IntegrationTest
  setup do
    @issue_area = issue_areas(:one)
  end

  test "should get index" do
    get issue_areas_url
    assert_response :success
  end

  test "should get new" do
    get new_issue_area_url
    assert_response :success
  end

  test "should create issue_area" do
    assert_difference('IssueArea.count') do
      post issue_areas_url, params: { issue_area: { name: @issue_area.name } }
    end

    assert_redirected_to issue_area_url(IssueArea.last)
  end

  test "should show issue_area" do
    get issue_area_url(@issue_area)
    assert_response :success
  end

  test "should get edit" do
    get edit_issue_area_url(@issue_area)
    assert_response :success
  end

  test "should update issue_area" do
    patch issue_area_url(@issue_area), params: { issue_area: { name: @issue_area.name } }
    assert_redirected_to issue_area_url(@issue_area)
  end

  test "should destroy issue_area" do
    assert_difference('IssueArea.count', -1) do
      delete issue_area_url(@issue_area)
    end

    assert_redirected_to issue_areas_url
  end
end
